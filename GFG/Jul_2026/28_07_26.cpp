class Solution {
  public:
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges) {
        // code here
        vector<vector<pair<int, int>>> adj(V);

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();

            int d = t.first;
            int u = t.second;

            if(d > dist[u]){
                continue;
            }

            for(auto &x : adj[u]){
                int v = x.first;
                int w = x.second;

                if(dist[v] > d + w){
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        if(dist[dest] == INT_MAX){
            return -1;
        }

        return dist[dest];
    }
};
