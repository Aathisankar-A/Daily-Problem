class Solution {
  public:
    int pathCountRec(vector<vector<int>>& mat, int i, int j, int k,
                 vector<vector<vector<int>>>& dp) {
    int n = mat.size();
    int m = mat[0].size();

    if (i >= n || j >= m) return 0;

    if (k < 0) return 0;

    if (i == n - 1 && j == m - 1)
        return (k == mat[i][j]);

    if (dp[i][j][k] != -1)
        return dp[i][j][k];
        
    int down = pathCountRec(mat, i + 1, j, k - mat[i][j], dp);
    int right = pathCountRec(mat, i, j + 1, k - mat[i][j], dp);

    return dp[i][j][k] = down + right;
}
  
    int numberOfPath(vector<vector<int>>& mat, int k) {
        // Code Here
        int n = mat.size();
        int m = mat[0].size();
    
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(k + 1, -1))
        );
    
        return pathCountRec(mat, 0, 0, k, dp);
    }
};
