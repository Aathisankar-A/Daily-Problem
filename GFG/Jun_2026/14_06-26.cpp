class Solution {
  public:
    vector<int> exitPoint(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();

        int row = 0, col = 0;
        int dir = 0; // 0->right, 1->down, 2->left, 3->up

        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};

        while(row >= 0 && row < n && col >= 0 && col < m){
            if(mat[row][col] == 1){
                dir = (dir + 1) % 4;
                mat[row][col] = 0;
            }

            row += dr[dir];
            col += dc[dir];
        }

        row -= dr[dir];
        col -= dc[dir];

        return {row, col};
    }
};
