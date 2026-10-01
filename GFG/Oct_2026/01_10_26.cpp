class Solution {
  public:
    int minTime(vector<int> &duration, vector<vector<int>> &dependencies) {
        // code here
        int n = duration.size();
        vector<vector<int>> adj(n);
        vector<int> in(n, 0), dp(n, 0);
        queue<int> q;

        for(auto &k : dependencies){
            int u = k[0];
            int v = k[1];

            adj[u].push_back(v);
            in[v]++;
        }

        for(int i = 0; i < n; i++){
            if(in[i] == 0){
                q.push(i);
                dp[i] = duration[i];
            }
        }

        int cnt = 0;
        int res = 0;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            cnt++;
            res = max(res, dp[u]);

            for(auto &v : adj[u]){
                dp[v] = max(dp[v], dp[u] + duration[v]);
                in[v]--;

                if(in[v] == 0){
                    q.push(v);
                }
            }
        }

        if(cnt != n){
            return -1;
        }

        return res;
    }
};
