class Solution {
  public:
    vector<int> maximumWeight(int n, vector<vector<int>> edges, vector<int>& queries) {
        // code here
        vector<int> par(n + 1), sz(n + 1, 1);

        for(int i = 1; i <= n; i++){
            par[i] = i;
        }

        sort(edges.begin(), edges.end(), [](auto &a, auto &b){
            return a[2] < b[2];
        });

        vector<pair<int, int>> q;

        for(int i = 0; i < queries.size(); i++){
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> ans(queries.size());
        long long cnt = 0;
        int j = 0;

        auto find = [&](auto&& self, int x) -> int{
            if(par[x] == x) return x;
            return par[x] = self(self, par[x]);
        };

        for(auto [x, idx] : q){
            while(j < edges.size() && edges[j][2] <= x){
                int u = find(find, edges[j][0]);
                int v = find(find, edges[j][1]);

                if(u != v){
                    cnt += 1LL * sz[u] * sz[v];

                    if(sz[u] < sz[v]){
                        swap(u, v);
                    }

                    par[v] = u;
                    sz[u] += sz[v];
                }

                j++;
            }

            ans[idx] = cnt;
        }

        return ans;
    }
};
