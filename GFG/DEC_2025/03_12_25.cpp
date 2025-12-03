class Solution {
  public:
    int helper(int mask, int curr, vector<vector<int>>& cost,
              vector<vector<int>>& dp){
        int n = cost.size();
    
        if(mask == (1 << n) - 1)
            return cost[curr][0];
    
        if(dp[curr][mask] != -1)
            return dp[curr][mask];
    
        int ans = INT_MAX;
    
        for(int i = 0; i < n; i++){
            if((mask & (1 << i)) == 0)
                ans = min(ans, cost[curr][i] + helper(mask | (1 << i), i, cost, dp));
        }
    
        return dp[curr][mask] = ans;
    }

    int tsp(vector<vector<int>>& cost) {
        // code here
        int n = cost.size();
        vector<vector<int>> dp(n, vector<int>(1 << n, -1));
    
        int mask = 1, curr = 0;
    
        return helper(mask, curr, cost, dp);
    }
};
