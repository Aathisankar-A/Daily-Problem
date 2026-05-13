class Solution {
  public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis){
        vis[node] = 1;

        for(int next : adj[node]){
            if(!vis[next]){
                dfs(next, adj, vis);
            }
        }
    }
    
    int findMotherVertex(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);

        for(auto &it : edges){
            adj[it[0]].push_back(it[1]);
        }

        int candidate = -1;

        vector<int> vis(V, 0);

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, adj, vis);
                candidate = i;
            }
        }

        vis.assign(V, 0);

        dfs(candidate, adj, vis);

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                return -1;
            }
        }

        for(int i = 0; i < candidate; i++){
            vis.assign(V, 0);

            dfs(i, adj, vis);

            bool ok = true;

            for(int j = 0; j < V; j++){
                if(!vis[j]){
                    ok = false;
                    break;
                }
            }

            if(ok){
                return i;
            }
        }

        return candidate;
    }
};
