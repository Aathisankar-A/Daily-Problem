class Solution {
  public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        // Code here
        vector<vector<int>> adj(n);
        vector<int> indeg(n, 0);

        for(auto &e : prerequisites){
            int u = e[1];
            int v = e[0];
            adj[u].push_back(v);
            indeg[v]++;
        }

        queue<int> q;

        for(int i = 0; i < n; i++){
            if(indeg[i] == 0)
                q.push(i);
        }

        int cnt = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;

            for(auto it : adj[node]){
                indeg[it]--;
                if(indeg[it] == 0)
                    q.push(it);
            }
        }

        return cnt == n;
    }
};
