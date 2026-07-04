class Solution {
public:
    void dfs(vector<vector<pair<int, int>>> &adj, int node, vector<int> &vis, int &mn){
        vis[node] = 1;

        for(auto nei : adj[node]){
            int nd = nei.first;
            int wt = nei.second;
            mn = min(mn, wt);

            if(!vis[nd]){
                dfs(adj, nd, vis, mn);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for(auto road : roads){
            int u = road[0];
            int v = road[1];
            int wt = road[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        int mn = INT_MAX;

        vector<int> vis(n+1);

        dfs(adj, 1, vis, mn);

        return mn;
    }
};
