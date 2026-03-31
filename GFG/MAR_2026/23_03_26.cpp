class Solution {
  public:
    int ans = -1;

    void dfs(int node, vector<int> &to, vector<int> &vis, vector<int> &pathVis, vector<int> &depth, int d){
        vis[node] = 1;
        pathVis[node] = 1;
        depth[node] = d;

        int next = to[node];

        if(next != -1){
            if(!vis[next]){
                dfs(next, to, vis, pathVis, depth, d + 1);
            }
            else if(pathVis[next]){
                ans = max(ans, d - depth[next] + 1);
            }
        }

        pathVis[node] = 0;
    }
    
    int longestCycle(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> to(V, -1);

        for(auto &e : edges){
            to[e[0]] = e[1];
        }

        vector<int> vis(V, 0), pathVis(V, 0), depth(V, 0);

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, to, vis, pathVis, depth, 0);
            }
        }

        return ans;
    }
};
