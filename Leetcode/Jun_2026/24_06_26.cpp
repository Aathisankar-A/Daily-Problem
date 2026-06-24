class Solution {
public:
    static const int MOD = 1000000007;

    vector<vector<long long>> mul(vector<vector<long long>> &a, vector<vector<long long>> &b){
        int n = a.size();

        vector<vector<long long>> c(n, vector<long long>(n, 0));

        for(int i = 0; i < n; i++){
            for(int k = 0; k < n; k++){
                if(a[i][k] == 0){
                    continue;
                }

                for(int j = 0; j < n; j++){
                    c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
                }
            }
        }

        return c;
    }

    vector<vector<long long>> matPow(vector<vector<long long>> a, int p){
        int n = a.size();

        vector<vector<long long>> res(n, vector<long long>(n, 0));

        for(int i = 0; i < n; i++){
            res[i][i] = 1;
        }

        while(p){
            if(p & 1){
                res = mul(res, a);
            }

            a = mul(a, a);
            p >>= 1;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<long long> dp(m);

        for(int i = 0; i < m; i++){
            dp[i] = i;
        }

        vector<vector<long long>> mat(m, vector<long long>(m, 0));

        for(int i = 1; i < m; i++){
            for(int j = m - i; j < m; j++){
                mat[i][j] = 1;
            }
        }

        vector<vector<long long>> pw = matPow(mat, n - 2);

        long long ans = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                ans = (ans + pw[i][j] * dp[j]) % MOD;
            }
        }

        return (ans * 2) % MOD;
    }
};
