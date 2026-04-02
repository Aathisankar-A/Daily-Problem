class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>> arr = mat;
        int n = mat.size();
        int m = mat[0].size();

        k = k % m;
        while(k){
            for(int i = 0; i < n; i+=2){
                int temp = arr[i][0];
                for(int j = 1; j < m; j++){
                    arr[i][j-1] = arr[i][j];
                }
                arr[i][m-1] = temp;
            }

            for(int i = 1; i < n; i++){
                int temp = arr[i][m-1];
                for(int j = m-2; j >= 0; j--){
                    arr[i][j+1] = arr[i][j];
                }
                arr[i][0] = temp;
            }
            k--;
        }
        return arr == mat;
    }
};
