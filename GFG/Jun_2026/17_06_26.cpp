class Solution {
  public:
    int maxProduct(int n) {
        // code here
        vector<int> dp(n + 1, 0);

        dp[1] = 1;

        for(int len = 2; len <= n; len++){

            int maxi = 0;

            for(int cut = 1; cut < len; cut++){

                int left = max(cut, dp[cut]);
                int right = max(len - cut, dp[len - cut]);

                maxi = max(maxi, left * right);
            }

            dp[len] = maxi;
        }

        return dp[n];
    }
};
