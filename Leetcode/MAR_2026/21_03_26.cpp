class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n = grid.size();
        int m = grid[0].size();

        // vector<vector<int>> ans(n, vector<int>(m, 0));

        int li = x;
        int ri = x + k - 1;

        while(li < ri){
            for(int col = y; col < y+k; col++){
                int temp = grid[li][col];
                grid[li][col] = grid[ri][col];
                grid[ri][col] = temp;
            }
            li++;
            ri--;
        }
        return grid;
    }
};
