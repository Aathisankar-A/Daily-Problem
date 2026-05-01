class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k+1, -1)));

        int fval = grid[0][0];
        int fscr = 0;
        int fcst = 0;

        if(fval == 1){
            fscr = 1;
            fcst = 1;
        }
        else if(fval == 2){
            fscr = 2;
            fcst = 1;
        }

        dp[0][0][fcst] = fscr;

        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                for(int j = 0; j <= k; j++){
                    if(dp[r][c][j] == -1)
                        continue;

                    if(r+1 < m){
                        int val = grid[r+1][c];
                        int scr = 0;
                        int cst = 0;
                        if(val == 1){
                           scr = 1;
                           cst = 1;
                        }
                        else if(val == 2){
                            scr = 2;
                            cst = 1;
                        }

                        int ncst = j + cst;

                        if(ncst <= k){
                            dp[r+1][c][ncst] = max(dp[r+1][c][ncst], dp[r][c][j] + scr);
                        }
                    }

                    if(c+1 < n){
                        int val = grid[r][c+1];
                        int scr = 0;
                        int cst = 0;
                        if(val == 1){
                           scr = 1;
                           cst = 1;
                        }
                        else if(val == 2){
                            scr = 2;
                            cst = 1;
                        }

                        int ncst = j + cst;

                        if(ncst <= k){
                            dp[r][c+1][ncst] = max(dp[r][c+1][ncst], dp[r][c][j] + scr);
                        }
                    }
                }
            }
        }
        int res = -1;
        
        for(int j = 0; j <= k; j++){
            res = max(res, dp[m-1][n-1][j]);
        }
        return res;
    }
};
