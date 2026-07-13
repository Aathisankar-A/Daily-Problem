class Solution {
  public:
    int minOperations(vector<int> &b) {
        // code here
        int MOD = 1e9 + 7;
        
        int n = b.size();
        
        int ans = 1;
        
        vector<int> vis(n+1, 0);
        
        for(int i = 1; i <= n; i++){
            if(vis[i] == 1)
                continue;
            
            int u = i;
            int cnt = 0;
            
            while(!vis[u]){
                vis[u] = 1;
                cnt++;
                u = b[u - 1];
            }
            
            ans = lcm(ans % MOD, cnt % MOD) % MOD;
        }
        return ans;
    }
};
