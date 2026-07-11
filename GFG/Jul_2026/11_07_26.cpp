class Solution {
  public:
    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    void dfs(int n, int m, vector<vector<int>> &mat, int i, int j, int xd, int yd, int cnt, int &ans){
        if(i == xd && j == yd){
            ans = max(ans, cnt);
            return;
        }
        
        mat[i][j] = 0;
        
        for(int k = 0; k < 4; k++){
            int ni = i + dir[k][0];
            int nj = j + dir[k][1];
            
            if(ni >= 0 && ni < n && nj >= 0 && nj < m && mat[ni][nj] != 0){
                dfs(n, m, mat, ni, nj, xd, yd, cnt+1, ans);
            }
        }
        mat[i][j] = 1;
    }
    
    int longestPath(vector<vector<int>>& mat, int xs, int ys, int xd, int yd) {
        // code here
        if(mat[xs][ys] == 0 || mat[xd][yd] == 0){
            return -1;
        }
        
        int n = mat.size();
        int m = mat[0].size();
        
        int ans = -1;
        
        dfs(n, m, mat, xs, ys, xd, yd, 0, ans);
        
        return ans;
    }
};
