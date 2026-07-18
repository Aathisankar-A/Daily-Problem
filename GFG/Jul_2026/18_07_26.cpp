class Solution {
  public:
    int findWays(vector<vector<int>>& matrix, int k) {
        // code here
        int mod = 1e9 + 7;
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> suf(n + 1, vector<int>(m + 1));

        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--)
                suf[i][j] = matrix[i][j] + suf[i + 1][j] + suf[i][j + 1] - suf[i + 1][j + 1];
        }

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 1)));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(suf[i][j] > 0)
                    dp[i][j][1] = 1;
            }
        }

        for(int p = 2; p <= k; p++){
            vector<vector<int>> sufRow(n + 1, vector<int>(m));

            for(int j = 0; j < m; j++){
                for(int i = n - 1; i >= 0; i--)
                    sufRow[i][j] = (sufRow[i + 1][j] + dp[i][j][p - 1]) % mod;
            }

            vector<vector<int>> sufCol(n, vector<int>(m + 1));

            for(int i = 0; i < n; i++){
                for(int j = m - 1; j >= 0; j--)
                    sufCol[i][j] = (sufCol[i][j + 1] + dp[i][j][p - 1]) % mod;
            }

            for(int i = n - 1; i >= 0; i--){
                for(int j = m - 1; j >= 0; j--){
                    if(suf[i][j] == 0)
                        continue;

                    int ans = 0;

                    int l = i + 1, r = n;

                    while(l < r){
                        int mid = (l + r) / 2;

                        if(suf[mid][j] < suf[i][j])
                            r = mid;
                        else
                            l = mid + 1;
                    }

                    if(l < n)
                        ans = (ans + sufRow[l][j]) % mod;

                    l = j + 1;
                    r = m;

                    while(l < r){
                        int mid = (l + r) / 2;

                        if(suf[i][mid] < suf[i][j])
                            r = mid;
                        else
                            l = mid + 1;
                    }

                    if(l < m)
                        ans = (ans + sufCol[i][l]) % mod;

                    dp[i][j][p] = ans;
                }
            }
        }

        return dp[0][0][k];
    }
};
