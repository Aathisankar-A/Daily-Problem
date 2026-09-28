class Solution {
  public:
    vector<int> seg;

    int gcd(int a, int b){
        while(b){
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    void build(int i, int l, int r, vector<int> &arr){
        if(l == r){
            seg[i] = arr[l];
            return;
        }

        int m = (l + r) / 2;

        build(2 * i + 1, l, m, arr);
        build(2 * i + 2, m + 1, r, arr);

        seg[i] = gcd(seg[2 * i + 1], seg[2 * i + 2]);
    }

    void update(int i, int l, int r, int idx, int val){
        if(l == r){
            seg[i] = val;
            return;
        }

        int m = (l + r) / 2;

        if(idx <= m){
            update(2 * i + 1, l, m, idx, val);
        }
        else{
            update(2 * i + 2, m + 1, r, idx, val);
        }

        seg[i] = gcd(seg[2 * i + 1], seg[2 * i + 2]);
    }

    int query(int i, int l, int r, int ql, int qr){
        if(ql <= l && r <= qr){
            return seg[i];
        }

        if(r < ql || l > qr){
            return 0;
        }

        int m = (l + r) / 2;

        int x = query(2 * i + 1, l, m, ql, qr);
        int y = query(2 * i + 2, m + 1, r, ql, qr);

        return gcd(x, y);
    }

    vector<int> processQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        int n = arr.size();

        seg.resize(4 * n);

        build(0, 0, n - 1, arr);

        vector<int> res;

        for(auto &k : queries){
            if(k[0] == 0){
                res.push_back(query(0, 0, n - 1, k[1], k[2]));
            }
            else{
                update(0, 0, n - 1, k[1], k[2]);
            }
        }

        return res;
    }
};
