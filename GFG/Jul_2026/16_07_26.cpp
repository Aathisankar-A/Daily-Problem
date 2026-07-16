class Solution {
  public:
    int rec(int i, int j, int n, vector<vector<int>> &dp){
        if(i == n){
            return j == 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = 0;
        int st = (i == 0) ? 1 : 0;

        for(int k = st; k <= 9; k++){
            if(k <= j)
                ans += rec(i+1, j-k, n, dp);
        }

        return dp[i][j] = ans;
    }
    
    int countWays(int n, int sum) {
        // code here
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

        int ans = rec(0, sum, n, dp);

        return ans == 0 ? -1 : ans;
    }
};
