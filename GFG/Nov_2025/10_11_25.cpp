class Solution {
  public:
    int helper(int i, int buy, vector<int>& arr, vector<vector<int>>& dp){
        int n = arr.size();

        if(i >= n)
            return 0;

        if(dp[i][buy] != -1)
            return dp[i][buy];
    
        
        if(buy){
            int take = -arr[i] + helper(i + 1, 0, arr, dp);
            int skip = helper(i + 1, 1, arr, dp);
            dp[i][buy] = max(take, skip);
        }
        else{
            int sell = arr[i] + helper(i + 2, 1, arr, dp);
            int skip = helper(i + 1, 0, arr, dp);
            dp[i][buy] = max(sell, skip);
        }
    
        return dp[i][buy];
    }

    int maxProfit(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        vector<vector<int>> dp(n, vector<int>(2, -1));
        
        return helper(0, 1, arr, dp);
    }
};
