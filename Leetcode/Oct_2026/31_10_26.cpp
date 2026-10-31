class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int MOD = 1000000007;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>> dp(n, vector<long long>(2, 0));
        dp[0][0] = 1;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i > 0){
                    if(grid[i - 1][j] == 0){
                        dp[j][0] = (dp[j][0] + dp[j][1]) % MOD;
                    }
                    else{
                        dp[j][0] = dp[j][1];
                    }
                }

                if(j > 0){
                    if(grid[i][j - 1] == 0){
                        dp[j][1] = (dp[j - 1][0] + dp[j - 1][1]) % MOD;
                    }
                    else{
                        dp[j][1] = dp[j - 1][0];
                    }
                }
            }
        }

        return (dp[n - 1][0] + dp[n - 1][1]) % MOD;
    }
};
