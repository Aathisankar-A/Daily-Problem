class Solution {
  public:
    int maxSumIS(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> dp(n);
        dp[0] = arr[0];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int maxSum = 0;
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i]) maxSum = max(maxSum, dp[j]);
            }
            dp[i] = maxSum + arr[i];
            ans = max(dp[i], ans);
        }
        return ans;
    }
};
