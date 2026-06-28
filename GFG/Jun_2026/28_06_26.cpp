class Solution {
  public:
    int mod = 1000000007;

    int dp[1005][1005][2];

    int rec(int i, int c, int last, int n, int k){
        if(c > k){
            return 0;
        }

        if(i == n){
            return c == k;
        }

        if(dp[i][c][last] != -1){
            return dp[i][c][last];
        }

        long long ans = 0;

        ans += rec(i + 1, c, 0, n, k);
        ans += rec(i + 1, c + (last == 1), 1, n, k);

        return dp[i][c][last] = ans % mod;
    }
    
    int countStrings(int n, int k) {
        // code here
        memset(dp, -1, sizeof(dp));

        long long ans = 0;

        ans += rec(1, 0, 0, n, k);
        ans += rec(1, 0, 1, n, k);

        return ans % mod;
    }
};
