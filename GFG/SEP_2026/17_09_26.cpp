class Solution {
  public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {
        // code here  
        vector<vector<pair<int, int>>> adj(n + 1);

        for(auto e : edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back({v, 0});
            adj[v].push_back({u, 1});
        }

        vector<int> dist(n + 1, INT_MAX);
        deque<int> dq;

        dist[src] = 0;
        dq.push_front(src);

        while(!dq.empty()){
            int u = dq.front();
            dq.pop_front();

            for(auto [v, wt] : adj[u]){
                if(dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;

                    if(wt == 0){
                        dq.push_front(v);
                    }
                    else{
                        dq.push_back(v);
                    }
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
