class Solution {
  public:
    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        vector<int> indegree(V,0);

        for(auto e:edges){
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adj[u].push_back({v,wt});
            indegree[v]++;
        }

        queue<int> q;

        for(int i = 0;i < V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> topo;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            topo.push_back(u);

            for(auto it:adj[u]){
                int v = it.first;

                indegree[v]--;

                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }

        vector<int> dis(V,INT_MIN);
        dis[src] = 0;

        for(int u:topo){
            if(dis[u] == INT_MIN){
                continue;
            }

            for(auto it:adj[u]){
                int v = it.first;
                int wt = it.second;

                dis[v] = max(dis[v],dis[u] + wt);
            }
        }

        return dis;
    }
};
