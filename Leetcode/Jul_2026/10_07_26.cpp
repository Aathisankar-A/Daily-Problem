class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> v(n);

        for(int i = 0; i < n; i++)
            v[i] = {nums[i], i};

        sort(v.begin(), v.end());

        vector<int> pos(n);

        for(int i = 0; i < n; i++)
            pos[v[i].second] = i;

        int lg = 18;

        vector<vector<int>> up(n, vector<int>(lg));

        int r = 0;

        for(int i = 0; i < n; i++){
            r = max(r, i);

            while(r + 1 < n &&
                  v[r + 1].first - v[r].first <= maxDiff &&
                  v[r + 1].first - v[i].first <= maxDiff)
                r++;

            up[i][0] = r;
        }

        for(int j = 1; j < lg; j++){
            for(int i = 0; i < n; i++){
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }

        vector<int> ans;

        for(auto &q : queries){
            int l = pos[q[0]];
            int r = pos[q[1]];

            if(l > r)
                swap(l, r);

            if(l == r){
                ans.push_back(0);
                continue;
            }

            int cur = l;
            int cnt = 0;

            for(int j = lg - 1; j >= 0; j--){
                if(up[cur][j] < r){
                    cur = up[cur][j];
                    cnt += (1 << j);
                }
            }

            if(up[cur][0] >= r)
                ans.push_back(cnt + 1);
            else
                ans.push_back(-1);
        }

        return ans;
    }
};
