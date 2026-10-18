class Solution {
  public:
    int minimumStep(int n) {
        // code here
        vector<int> dp(n + 1, INT_MAX);
        dp[1] = 0;

        for(int i = 1; i < n; i++){
            dp[i + 1] = min(dp[i + 1], dp[i] + 1);

            if(3 * i <= n)
                dp[3 * i] = min(dp[3 * i], dp[i] + 1);
        }

        return dp[n];

    }
};
