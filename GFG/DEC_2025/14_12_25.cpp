class Solution {
public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> arr(n, vector<int>(m));

        for(int j = 0; j < m; j++){
            arr[0][j] = mat[0][j];
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                arr[i][j] = mat[i][j] + arr[i - 1][j];
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 1; j < m; j++){
                arr[i][j] += arr[i][j - 1];
            }
        }

        vector<int> res;

        for(auto &q : queries){
            int r1 = q[0];
            int c1 = q[1];
            int r2 = q[2];
            int c2 = q[3];

            int sum = arr[r2][c2];

            if(r1 > 0)
                sum -= arr[r1 - 1][c2];

            if(c1 > 0)
                sum -= arr[r2][c1 - 1];

            if(r1 > 0 && c1 > 0)
                sum += arr[r1 - 1][c1 - 1];

            res.push_back(sum);
        }

        return res;
    }
};
