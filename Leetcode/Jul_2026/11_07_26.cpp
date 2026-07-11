class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& vis, int s, vector<int>& res){
        vis[s] = true;
        res.push_back(s);

        for(int i : adj[s]){
            if(!vis[i]){
                dfs(adj, vis, i, res);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        vector<bool> vis(n, false);
        vector<vector<int>> comp;

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                vector<int> c;
                dfs(adj, vis, i, c);
                comp.push_back(c);
            }
        }
        
        int ans = 0;

        for(auto &i : comp){
            int m = i.size();
            bool flag = true;
            
            for(int &j : i){
                if(adj[j].size() < m-1){
                    flag = false;
                    break;
                }
            }

            if(flag){
                ans++;
            }
        }
        return ans;
    }
};
