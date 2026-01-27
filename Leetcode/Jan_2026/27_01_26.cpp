class Solution {
public:
    void buildGraph(vector<vector<pair<int,int>>>& graph, vector<vector<int>>& edges){
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            graph[u].push_back({v, w});
            graph[v].push_back({u, 2*w});
        }
    }

    int minCost(int n, vector<vector<int>>& edges){
        vector<vector<pair<int,int>>> graph(n);
        buildGraph(graph, edges);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int> dis(n, INT_MAX);
        dis[0] = 0;

        pq.push({0, 0});

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int d = top.first;
            int u = top.second;

            if(d > dis[u])
                continue;

            for(auto& p : graph[u]){
                int v = p.first;
                int w = p.second;

                if(dis[v] > dis[u] + w){
                    dis[v] = dis[u] + w;
                    pq.push({dis[v], v});
                }
            }
        }

        if(dis[n - 1] == INT_MAX)
            return -1;

        return dis[n - 1];
    }
};
