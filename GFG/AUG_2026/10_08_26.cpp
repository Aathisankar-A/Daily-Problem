class Solution {
  public:
    int maxTask(vector<int>& h, vector<int>& l) {
        // code here
        int n = h.size();

        vector<int> dp(n + 1, 0);

        for(int i = 1; i <= n; i++){
            dp[i] = dp[i - 1] + l[i - 1];

            if(i == 1){
                dp[i] = max(dp[i], h[i - 1]);
            }
            else{
                dp[i] = max(dp[i], dp[i - 2] + h[i - 1]);
            }
        }

        return dp[n];
    }
};
