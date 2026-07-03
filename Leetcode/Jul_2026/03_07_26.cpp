class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        vector<vector<pair<int, int>>> adj(n);
        vector<int> indegree(n, 0);

        for(auto &it : edges){
            adj[it[0]].push_back({it[1], it[2]});
            indegree[it[1]]++;
        }

        queue<int> q;

        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> topo;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            topo.push_back(u);

            for(auto &[v, wt] : adj[u]){
                indegree[v]--;

                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }

        auto check = [&](int lim){

            const long long INF = 1e18;

            vector<long long> dp(n, INF);
            dp[0] = 0;

            for(auto u : topo){

                if(dp[u] == INF){
                    continue;
                }

                if(u != 0 && u != n - 1 && !online[u]){
                    continue;
                }

                for(auto &[v, wt] : adj[u]){

                    if(wt < lim){
                        continue;
                    }

                    if(v != n - 1 && !online[v]){
                        continue;
                    }

                    dp[v] = min(dp[v], dp[u] + wt);
                }
            }

            return dp[n - 1] <= k;
        };

        int low = 0;
        int high = 1e9;
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(check(mid)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }
};
