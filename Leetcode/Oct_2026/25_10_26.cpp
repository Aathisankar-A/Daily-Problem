class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int m, int n){
        if(i < 0 || i >= m || j < 0 || j >= n)
            return;

        if(grid[i][j] == 1)
            return;

        grid[i][j] = 1;

        dfs(grid, i + 1, j, m, n);
        dfs(grid, i - 1, j, m, n);
        dfs(grid, i, j + 1, m, n);
        dfs(grid, i, j - 1, m, n);
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++){
            dfs(grid, i, 0, m, n);
            dfs(grid, i, n - 1, m, n);
        }

        for(int j = 0; j < n; j++){
            dfs(grid, 0, j, m, n);
            dfs(grid, m - 1, j, m, n);
        }

        int ans = 0;

        for(int i = 1; i < m - 1; i++){
            for(int j = 1; j < n - 1; j++){
                if(grid[i][j] == 0){
                    ans++;
                    dfs(grid, i, j, m, n);
                }
            }
        }

        return ans;
    }
};
