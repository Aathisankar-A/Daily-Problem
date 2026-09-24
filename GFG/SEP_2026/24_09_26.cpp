class Solution {
  public:
    int maxStackHeight(vector<int> &r, vector<int> &h) {
        // code here
        int n = r.size();

        vector<pair<int, int>> a;

        for(int i = 0; i < n; i++){
            a.push_back({r[i], h[i]});
        }

        sort(a.begin(), a.end(), [](auto &x, auto &y){
            if(x.first != y.first){
                return x.first < y.first;
            }

            return x.second > y.second;
        });

        vector<int> bit(1002, 0);

        auto query = [&](int x){
            int res = 0;

            while(x > 0){
                res = max(res, bit[x]);
                x -= x & -x;
            }

            return res;
        };

        auto update = [&](int x, int val){
            while(x <= 1001){
                bit[x] = max(bit[x], val);
                x += x & -x;
            }
        };

        int res = 0;

        for(auto [r, h] : a){
            int cur = query(h - 1) + h;
            res = max(res, cur);
            update(h, cur);
        }

        return res;
    }
};
