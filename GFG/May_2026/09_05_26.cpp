class Solution {
  public:
    int countSpanTree(int n, vector<vector<int>>& edges) {
        // code here
        if(n == 1){
            return 1;
        }

        vector<vector<long long>> laplacian(n, vector<long long>(n, 0));

        for(auto &it : edges){
            int u = it[0];
            int v = it[1];

            laplacian[u][u]++;
            laplacian[v][v]++;

            laplacian[u][v]--;
            laplacian[v][u]--;
        }

        vector<vector<long double>> mat(n - 1, vector<long double>(n - 1));

        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < n - 1; j++){
                mat[i][j] = laplacian[i][j];
            }
        }

        long double det = 1;

        for(int i = 0; i < n - 1; i++){
            int pivot = i;

            for(int j = i; j < n - 1; j++){
                if(fabsl(mat[j][i]) > fabsl(mat[pivot][i])){
                    pivot = j;
                }
            }

            if(fabsl(mat[pivot][i]) < 1e-9){
                return 0;
            }

            if(i != pivot){
                swap(mat[i], mat[pivot]);
                det *= -1;
            }

            det *= mat[i][i];

            for(int j = i + 1; j < n - 1; j++){
                long double factor = mat[j][i] / mat[i][i];

                for(int k = i; k < n - 1; k++){
                    mat[j][k] -= factor * mat[i][k];
                }
            }
        }

        return (int)round(det);
    }
};
