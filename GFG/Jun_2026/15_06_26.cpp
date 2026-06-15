class Solution {
  public:
    int minimumCost(vector<int> &cost, int w) {
        // code here
        vector<int> dp(w + 1, 1e9);

        dp[0] = 0;

        int n = cost.size();

        for(int wt = 1; wt <= n; wt++){
            if(cost[wt - 1] == -1)
                continue;

            for(int i = wt; i <= w; i++){
                dp[i] = min(dp[i], dp[i - wt] + cost[wt - 1]);
            }
        }

        return dp[w] == 1e9 ? -1 : dp[w];
    }
};
