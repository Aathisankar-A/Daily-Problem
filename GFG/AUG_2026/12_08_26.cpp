class Solution {
  public:
    vector<int> findWays(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int mod = 1e9 + 7;

        vector<vector<int>> ways(n, vector<int>(n, 0));
        vector<vector<int>> best(n, vector<int>(n, 0));

        ways[0][0] = 1;
        best[0][0] = grid[0][0];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0)
                    continue;

                if(i > 0 && (grid[i-1][j] == 2 || grid[i-1][j] == 3)){
                    ways[i][j] = (ways[i][j] + ways[i-1][j]) % mod;
                    best[i][j] = max(best[i][j], best[i-1][j]);
                }

                if(j > 0 && (grid[i][j-1] == 1 || grid[i][j-1] == 3)){
                    ways[i][j] = (ways[i][j] + ways[i][j-1]) % mod;
                    best[i][j] = max(best[i][j], best[i][j-1]);
                }

                if(ways[i][j] > 0)
                    best[i][j] += grid[i][j];
            }
        }

        return {ways[n-1][n-1], best[n-1][n-1]};
    }
};
