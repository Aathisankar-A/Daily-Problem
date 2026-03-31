class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> sum(2, vector<int>(m+1, 0));
        vector<vector<int>> cntX(2, vector<int>(m+1, 0));

        int ans = 0;

        for(int i = 0; i < n; i++){
            int curr = i % 2;
            int prev = 1 - curr;

            for(int j = 0; j < m; j++){
                int val = (grid[i][j] == 'X') ? 1 : (grid[i][j] == 'Y' ? -1 : 0);
                int isX = (grid[i][j] == 'X') ? 1 : 0;

                sum[curr][j+1] = val + sum[curr][j] + sum[prev][j+1] - sum[prev][j];
                cntX[curr][j+1] = isX + cntX[curr][j] + cntX[prev][j+1] - cntX[prev][j];

                if(sum[curr][j+1] == 0 && cntX[curr][j+1] > 0){
                    ans++;
                }
            }
        }
        return ans;
    }
};
