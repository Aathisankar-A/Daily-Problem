class SegmentTree {
public:
    vector<long long> seg;
    int n;

    long long lcm(long long a, long long b){
        return (a / __gcd(a, b)) * b;
    }

    SegmentTree(vector<int>& arr){
        n = arr.size();
        seg.resize(4 * n);
        build(0, 0, n - 1, arr);
    }

    void build(int ind, int low, int high, vector<int>& arr){

        if(low == high){
            seg[ind] = arr[low];
            return;
        }

        int mid = (low + high) / 2;

        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);

        seg[ind] = lcm(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    void update(int ind, int low, int high, int i, int val){

        if(low == high){
            seg[ind] = val;
            return;
        }

        int mid = (low + high) / 2;

        if(i <= mid)
            update(2 * ind + 1, low, mid, i, val);
        else
            update(2 * ind + 2, mid + 1, high, i, val);

        seg[ind] = lcm(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    long long query(int ind, int low, int high, int l, int r){

        if(r < low || high < l)
            return 1;

        if(l <= low && high <= r)
            return seg[ind];

        int mid = (low + high) / 2;

        long long left = query(2 * ind + 1, low, mid, l, r);
        long long right = query(2 * ind + 2, mid + 1, high, l, r);

        return lcm(left, right);
    }
};

class Solution {
  public:
    vector<long long> RangeLCMQuery(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        SegmentTree st(arr);

        vector<long long> ans;

        for(int i = 0; i < queries.size(); i++){

            int type = queries[i][0];

            //Task 1 : Update query
            if(type == 1){

                int index = queries[i][1];
                int value = queries[i][2];

                st.update(0, 0, arr.size() - 1, index, value);
            }

            //Task 2 : Range LCM query
            else{

                int l = queries[i][1];
                int r = queries[i][2];

                ans.push_back(st.query(0, 0, arr.size() - 1, l, r));
            }
        }

        return ans;
    }
};
