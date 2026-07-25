class Solution {
  public:
    int maximumSum(vector<vector<int>>& mat, int k) {
        // code here
        int n = mat.size();

        vector<vector<int>> pre(n + 1, vector<int>(n + 1, 0));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                pre[i][j] = mat[i - 1][j - 1] + pre[i - 1][j]
                          + pre[i][j - 1] - pre[i - 1][j - 1];
            }
        }

        int ans = INT_MIN;

        for(int i = 0; i <= n - k; i++){
            for(int j = 0; j <= n - k; j++){
                int sum = pre[i + k][j + k] - pre[i][j + k]
                        - pre[i + k][j] + pre[i][j];

                ans = max(ans, sum);
            }
        }

        return ans;
    }
};
