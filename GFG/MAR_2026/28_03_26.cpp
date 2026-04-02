class Solution {
  public:
    void dfs(int node, int parent, vector<int>& vis, vector<int>& tin, vector<int>& low,
         vector<int>& mark, vector<vector<int>>& adj, int& timer){

        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;

        int child = 0;

        for(auto it : adj[node]){
            if(it == parent) continue;

            if(!vis[it]){
                dfs(it, node, vis, tin, low, mark, adj, timer);

                low[node] = min(low[node], low[it]);

                if(low[it] >= tin[node] && parent != -1){
                    mark[node] = 1;
                }

                child++;
            }
            else{
                low[node] = min(low[node], tin[it]);
            }
        }

        if(parent == -1 && child > 1){
            mark[node] = 1;
        }
    }
    
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);

        for(auto it : edges){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(V, 0), tin(V), low(V), mark(V, 0);
        int timer = 0;

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, -1, vis, tin, low, mark, adj, timer);
            }
        }

        vector<int> ans;

        for(int i = 0; i < V; i++){
            if(mark[i] == 1){
                ans.push_back(i);
            }
        }

        if(ans.size() == 0){
            return {-1};
        }

        return ans;
    }
};
