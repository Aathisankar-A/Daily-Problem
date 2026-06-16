class Solution {
  public:
    vector<int> constructList(vector<vector<int>> &queries) {
        // code here
        vector<int> ans;
        int xr = 0;

        ans.push_back(0);

        for (auto &q : queries) {
            int type = q[0];
            int x = q[1];

            if (type == 0) {
                ans.push_back(x ^ xr);
            } else {
                xr ^= x;
            }
        }

        for (int &x : ans) {
            x ^= xr;
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};
