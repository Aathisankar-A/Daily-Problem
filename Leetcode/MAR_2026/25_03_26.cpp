class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        //horizontal

        vector<long long> prefix_row(n, 0);

        for(int i = 0; i < m; i++)
            prefix_row[0] += grid[0][i];

        for(int i = 1; i < n; i++){
            long long row_sum = 0;
            for(int j = 0; j < m; j++){
                row_sum += grid[i][j];
            }
            prefix_row[i] = prefix_row[i-1] + row_sum;
        }

        for(int i = 0; i < n-1; i++){
            long long p1 = prefix_row[i];
            long long p2 = prefix_row[n-1] - p1;

            if(p1 == p2)
                return true;
        }

        // vertical

        vector<long long> prefix_col(m, 0);

        for(int i = 0; i < n; i++)
            prefix_col[0] += grid[i][0];

        for(int i = 1; i < m; i++){
            long long col_sum = 0;
            for(int j = 0; j < n; j++){
                col_sum += grid[j][i];
            }
            prefix_col[i] = prefix_col[i-1] + col_sum;
        }

        for(int i = 0; i < m-1; i++){
            long long p1 = prefix_col[i];
            long long p2 = prefix_col[m-1] - p1;

            if(p1 == p2)
                return true;
        }
        return false;
    }
};
