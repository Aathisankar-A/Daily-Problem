class Solution {
  public:
    const int mod = 1e9 + 7;

    // int rec(int n, int m, vector<int> &dp){
    //     if(n == 0){
    //         return 1;
    //     }

    //     if(dp[n] != -1){
    //         return dp[n];
    //     }

    //     if(n < m){
    //         return dp[n] = rec(n - 1, m, dp);
    //     }

    //     return dp[n] = (rec(n - 1, m, dp) + rec(n - m, m, dp)) % mod;
    // }
    
    int countWays(int n, int m) {
        // code here
        // vector<int> dp(n + 1, -1);
        // return rec(n, m, dp);
        
        const int mod = 1e9 + 7;

        vector<long long> dp(n + 1);

        dp[0] = 1;

        for(int i = 1; i <= n; i++){
            dp[i] = dp[i - 1];

            if(i >= m){
                dp[i] = (dp[i] + dp[i - m]) % mod;
            }
        }

        return dp[n];
    }
};
