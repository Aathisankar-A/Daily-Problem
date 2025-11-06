class Solution {
  public:
    int helper(int n, vector<int> &dp) {
        if (n < 0) return 0;
        
        if (n == 0) return 1;
        
        if (dp[n] != -1)
            return dp[n];
        
        int ans = 0;
        
        ans = helper(n-1, dp);
        
        ans += helper(n-2, dp);
        
        return dp[n] = ans;
    }


    int numberOfWays(int n) {
        // code here
        vector<int> dp(n+1, -1);
        
        return helper(n, dp);
    }
};
