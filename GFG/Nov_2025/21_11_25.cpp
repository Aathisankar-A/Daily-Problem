class Solution{
  public:
    vector<vector<array<int, 3>>> buildAdj(int V, vector<vector<int>>& edges){
        vector<vector<array<int, 3>>> adj(V);

        for(int i = 0; i < edges.size(); i++){
            int x = edges[i][0];
            int y = edges[i][1];
            int w1 = edges[i][2];
            int w2 = edges[i][3];

            adj[x].push_back({y, w1, w2});
            adj[y].push_back({x, w1, w2});
        }

        return adj;
    }

    int shortestPath(int V, int a, int b, vector<vector<int>>& edges){
        vector<vector<array<int, 3>>> adj = buildAdj(V, edges);

        long long INF = 1e15;
        vector<vector<long long>> dist(V, vector<long long>(2, INF));

        using State = array<long long, 3>;
        priority_queue<State, vector<State>, greater<State>> pq;

        dist[a][0] = 0;
        pq.push({0, a, 0});

        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();

            long long d = cur[0];
            int node = cur[1];
            int used = cur[2];

            if(d != dist[node][used]){
                continue;
            }

            for(auto& it : adj[node]){
                int nxt = it[0];
                long long w1 = it[1];
                long long w2 = it[2];

                if(dist[nxt][used] > d + w1){
                    dist[nxt][used] = d + w1;
                    pq.push({dist[nxt][used], nxt, used});
                }

                if(used == 0){
                    if(dist[nxt][1] > d + w2){
                        dist[nxt][1] = d + w2;
                        pq.push({dist[nxt][1], nxt, 1});
                    }
                }
            }
        }

        long long ans = min(dist[b][0], dist[b][1]);
        return ans >= INF ? -1 : ans;
    }
};
