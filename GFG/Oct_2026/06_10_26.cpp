class Solution {
  public:
    int longIncPath(vector<vector<int>> &mat, int n, int m) {
        // code here
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int res = 0;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        function<int(int, int)> dfs = [&](int i, int j){
            if(dp[i][j]){
                return dp[i][j];
            }

            int ans = 1;

            for(int k = 0; k < 4; k++){
                int x = i + dx[k];
                int y = j + dy[k];

                if(x >= 0 && x < n && y >= 0 && y < m && mat[x][y] > mat[i][j]){
                    ans = max(ans, 1 + dfs(x, y));
                }
            }

            return dp[i][j] = ans;
        };

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                res = max(res, dfs(i, j));
            }
        }

        return res;
    }
};
