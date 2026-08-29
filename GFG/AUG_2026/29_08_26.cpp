class Solution {
  public:
    int countSubsequences(string& s, int n) {
        // code here
        int mod = 1e9 + 7;
        vector<int> dp(n);

        for(char c : s){
            int d = c - '0';
            vector<int> ndp = dp;

            ndp[d % n]++;

            for(int r = 0; r < n; r++){
                int nr = (r * 10 + d) % n;
                ndp[nr] = (ndp[nr] + dp[r]) % mod;
            }

            dp = ndp;
        }

        return dp[0];
    }
};
