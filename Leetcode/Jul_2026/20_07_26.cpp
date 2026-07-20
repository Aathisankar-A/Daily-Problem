class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int tot = n * m;

        vector<vector<int>> ans(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int curr = i*m + j;
                int targ = (curr + k) % (tot);

                int ni = targ / m;
                int nj = targ % m;

                ans[ni][nj] = grid[i][j];
            }
        }
        return ans;
    }
};
