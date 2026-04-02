class Solution {
  public:
    int rec(int n, int i, int last, vector<vector<int>>& dp){
        if(i == n){
            return 1;
        }
        
        if(dp[i][last] != -1){
            return dp[i][last];
        }
        
        int zero = rec(n, i+1, 0, dp);
        
        int one = 0;
        if(last == 0){
            one = rec(n, i+1, 1, dp);
        }
        
        return dp[i][last] = zero + one;
    }
    
    int countStrings(int n) {
        // code here
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return rec(n, 1, 0, dp) + rec(n, 1, 1, dp);
    }
};
