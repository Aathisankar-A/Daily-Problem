class Solution {
  public:
    int helper(int i1, int j1, int j2, vector<vector<int>> &mat, 
                  vector<vector<vector<int>>> &dp) {
        int n = mat.size();
        int m = mat[0].size();
    
        int i2 = i1 + j1 - j2;
    
        if (i1 >= n || i2 >= n || j1 >= m || j2 >= m)
            return INT_MIN;
    
        if (mat[i1][j1] == -1 || mat[i2][j2] == -1)
            return INT_MIN;
    
        if (i1 == n - 1 && j1 == m - 1 && j2 == m - 1)
            return mat[i1][j1];

        if (dp[i1][j1][j2] != -1)
            return dp[i1][j1][j2];
    
        int res = INT_MIN;
        
        int dir[2][2] = {{1, 0}, {0, 1}};
        for (auto &d1 : dir) {
            for (auto &d2 : dir) {
                int newRow1 = i1 + d1[0];
                int newCol1 = j1 + d1[1];
                int newCol2 = j2 + d2[1];
    
                res = max(res, helper(newRow1, newCol1, newCol2, mat, dp));
            }
        }
        res += mat[i1][j1];

        if (i1 != i2)
            res += mat[i2][j2];
    
        return dp[i1][j1][j2] = res;
    }
    
    int chocolatePickup(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    
        return max(0, helper(0, 0, 0, mat, dp));
    }
};
