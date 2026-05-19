class Solution {
  public:
    // int solve(int n, vector<int>& dp){
    //     if(n <= 0){
    //         return 0;
    //     }
        
    //     if(dp[n] != -1){
    //         return dp[n];
    //     }
        
    //     dp[n] = max(n, solve(n/2, dp) + solve(n/3, dp) + solve(n/4, dp));
    //     return dp[n];
    // }
    
    int maxSum(int n) {
        // code here.
        vector<int> dp(n+1, 0);
        
        // return max(n, solve(n, dp));
        
        for(int i = 1; i <= n; i++){
            dp[i] = max(i, dp[i/2] + dp[i/3] + dp[i/4]);
        }
        
        return dp[n];
    }
};
