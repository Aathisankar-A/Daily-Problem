class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int MOD = 1000000007;
        int m = r - l + 1;

        vector<long long> dp(m, 1);

        for(int len = 2; len <= n; len++){
            reverse(dp.begin(), dp.end());

            long long sum = 0;

            for(int i = 0; i < m; i++){
                long long x = dp[i];

                dp[i] = sum;

                sum = (sum + x) % MOD;
            }
        }

        long long ans = 0;

        for(int i = 0; i < m; i++){
            ans = (ans + dp[i]) % MOD;
        }

        return (ans * 2) % MOD;
    }
};
