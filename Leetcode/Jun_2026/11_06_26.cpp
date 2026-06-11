class Solution {
public:
    int powMod(int x, int n, int M) {
        long long res = 1;
        long long base = x;

        while(n > 0) {
            if(n & 1)
                res = (res * base) % M;

            base = (base * base) % M;
            n >>= 1;
        }

        return (int)res;
    }

    void dfs(vector<vector<int>> &adj, vector<int> &vis, int node, int &mx, int depth){
        vis[node] = 1;

        mx = max(mx, depth);

        for(int nd : adj[node]){
            if(vis[nd] == 0){
                dfs(adj, vis, nd, mx, depth + 1);
            }
        }
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);

        for(int i = 0; i < n - 1; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n + 1, 0);
        int mx = 0;

        dfs(adj, vis, 1, mx, 0);

        return powMod(2, mx - 1, 1000000007);
    }
};
