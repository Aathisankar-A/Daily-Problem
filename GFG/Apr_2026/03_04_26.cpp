class Solution {
  public:
    vector<int> diagView(vector<vector<int>> mat) {
        // code here
        int n = mat.size();
        vector<int> res;

        // start from first row
        for(int col = 0; col < n; col++){
            int i = 0;
            int j = col;

            while(i < n && j >= 0){
                res.push_back(mat[i][j]);
                i++;
                j--;
            }
        }

        // start from last column (excluding first row)
        for(int row = 1; row < n; row++){
            int i = row;
            int j = n - 1;

            while(i < n && j >= 0){
                res.push_back(mat[i][j]);
                i++;
                j--;
            }
        }

        return res;
    }
};
