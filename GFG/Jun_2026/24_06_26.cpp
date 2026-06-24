class Solution {
  public:
    bool rec(int n, vector<vector<int>> &mat, int i, int j, vector<vector<int>> &ans, vector<vector<int>> &dp){
        if(i == n-1 && j == n-1){
            ans[i][j] = 1;
            return true;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        for(int jump = 1; jump <= mat[i][j]; jump++){
            
            if(i < n && j < n && j+jump < n && mat[i][j+jump] != 0 
            && ans[i][j+jump] == 0){
                
                ans[i][j+jump] = 1;
                
                if(rec(n, mat, i, j+jump, ans, dp)){
                    return dp[i][j] = 1;
                }
                ans[i][j+jump] = 0;
                
            }
            
            if(i < n && j < n && i+jump < n && mat[i+jump][j] != 0 
            && ans[i+jump][j] == 0){
                
                ans[i+jump][j] = 1;
                
                if(rec(n, mat, i+jump, j, ans, dp)){
                    return dp[i][j] = 1;
                }
                ans[i+jump][j] = 0;
            }
        }
        return dp[i][j] = 0;
    }
    
    vector<vector<int>> shortestDist(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        
        vector<vector<int>> ans(n, vector<int>(n, 0));
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        ans[0][0] = 1;
        
        if(rec(n, mat, 0, 0, ans, dp)){
            return ans;
        }
        return {{-1}};
    }
};
