class Solution {
  public:
    pair<int,int> bfs(int s, vector<vector<int>>& adj){
        int n = adj.size();
        int node = s, d = 0;

        vector<int> dis(n, -1);
        queue<int> q;

        q.push(s);
        dis[s - 1] = 0;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int v : adj[u - 1]){
                if(dis[v - 1] == -1){
                    dis[v - 1] = dis[u - 1] + 1;
                    q.push(v);

                    if(dis[v - 1] > d){
                        node = v;
                        d = dis[v - 1];
                    }
                }
            }
        }

        return {d, node};
    }
    
    int partyHouse(vector<vector<int>> &adj) {
        // code here
        int node = bfs(1, adj).second;
        int d = bfs(node, adj).first;

        return (d + 1) / 2;
    }
};
