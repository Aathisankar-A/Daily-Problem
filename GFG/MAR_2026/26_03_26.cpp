class Solution {
  public:
    void generateAdj(vector<vector<pair<int,int>>>& adj, vector<vector<int>>& edges){
        for(vector<int>& vec : edges){
            int u = vec[0];
            int v = vec[1];
            int wt = vec[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
    }
    
    int countPaths(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>> adj(V);
        generateAdj(adj, edges);
        
        vector<int> minTime(V, INT_MAX);

        vector<int> paths(V, 0);
        minTime[0] = 0;
        paths[0] = 1;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
    
        while(!pq.empty()){
            auto top = pq.top(); pq.pop();
            int node = top.second;
            int currentTime = top.first;
    
            if(currentTime > minTime[node])
                continue;
    
            for(auto& next : adj[node]){
                int nextNode = next.first;
                int nextTime = next.second;
                int newTime = nextTime + currentTime;

                if(newTime < minTime[nextNode]){
                    minTime[nextNode] = newTime;
                    paths[nextNode] = paths[node];
                    pq.push({newTime, nextNode});
                }
                else if(newTime == minTime[nextNode]){
                    paths[nextNode] = (paths[nextNode] + paths[node]);
                }
            }
        }

        return paths[V - 1];
    }
};
