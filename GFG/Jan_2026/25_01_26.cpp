class Solution {
  public:
    int findWays(int n) {
        // code here
        if(n % 2 != 0)
            return 0;

        int k = n / 2;
        vector<int> dp(k + 1, 0);
        dp[0] = 1;

        for(int i = 1; i <= k; i++){
            for(int j = 0; j < i; j++){
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }
        return dp[k];
    }
};
