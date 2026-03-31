class Solution {
  public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        // Code here
        if(V == 1) return {0};

        vector<vector<int>> adj(V);
        vector<int> degree(V, 0);

        // Build graph
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            degree[u]++;
            degree[v]++;
        }

        queue<int> q;

        // Push all leaf nodes
        for(int i = 0; i < V; i++){
            if(degree[i] == 1)
                q.push(i);
        }

        int remaining = V;

        // Remove leaves level by level
        while(remaining > 2){
            int size = q.size();
            remaining -= size;

            while(size--){
                int node = q.front();
                q.pop();

                for(auto &nei : adj[node]){
                    degree[nei]--;

                    if(degree[nei] == 1)
                        q.push(nei);
                }
            }
        }

        vector<int> ans;

        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};
