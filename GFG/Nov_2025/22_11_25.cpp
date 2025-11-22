class Solution {
  public:
    vector<vector<int>> buildAdj(int V, vector<vector<int>>& edges){
        vector<vector<int>> adj(V);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }
    
    void dfs(int start, vector<vector<int>>& adj, vector<bool>& vis){
        vis[start] = true;
        for(int nbr : adj[start]){
            if(!vis[nbr])
                dfs(nbr, adj, vis);
        }
    }
    
    int minConnect(int V, vector<vector<int>>& edges){
        //code here
        vector<vector<int>> adj = buildAdj(V, edges);
        
        vector<bool> vis(V, false);
        int edgeCount = 0;

        for(int i = 0; i < V; i++)
            edgeCount += adj[i].size();
        edgeCount /= 2;

        int comp = 0;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                comp++;
                dfs(i, adj, vis);
            }
        }

        if(edgeCount < V - 1)
            return -1;

        int extra = edgeCount - (V - comp);

        if(extra >= (comp - 1))
            return comp - 1;

        return -1;
    }
};
