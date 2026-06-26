class Solution {
  public:
    int mod = 1e9 + 7;

    int rec(string &s1, string &s2, int i, int j, vector<vector<int>> &dp){
        if(j == s2.size()){
            return 1;
        }

        if(i == s1.size()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        long long ans = rec(s1, s2, i + 1, j, dp);

        if(s1[i] == s2[j]){
            ans += rec(s1, s2, i + 1, j + 1, dp);
        }

        return dp[i][j] = ans % mod;
    }
    
    int countWays(string &s1, string &s2) {
        // code here
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return rec(s1, s2, 0, 0, dp);
    }
};
