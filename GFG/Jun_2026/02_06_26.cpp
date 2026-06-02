class Solution {
  public:
    int sumDiffPairs(vector<int>& arr, int k) {
        // code here
        int n = arr.size();

        sort(arr.begin(), arr.end());

        vector<int> dp(n, 0);

        for(int i = 1; i < n; i++){
            dp[i] = dp[i - 1];

            if(arr[i] - arr[i - 1] < k){
                int curr = arr[i] + arr[i - 1];

                if(i >= 2){
                    curr += dp[i - 2];
                }

                dp[i] = max(dp[i], curr);
            }
        }

        return dp[n - 1];
    }
};
