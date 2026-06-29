class Solution {
  public:
    long long rec(vector<int> &a, vector<int> &b, int n, int m, int i, int j, 
    vector<vector<int>> &dp){
        
        if(j == m){
            return 0;
        }

        if(i == n){
            return 0;
        }

        if(n - i < m - j){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        long long pick = a[i] * b[j] + rec(a, b, n, m, i+1, j+1, dp);
        long long notPick = rec(a, b, n, m, i+1, j, dp);
        
        return dp[i][j] = max(pick, notPick);
    }
     
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        // code here
        int n = a.size();
        int m = b.size();
        
        vector<vector<int>> dp(n, vector<int>(n,-1));
        
        return (int)rec(a, b, n, m, 0, 0, dp);
    }
};
