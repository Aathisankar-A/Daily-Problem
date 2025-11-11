class Solution {
  public:
    int helper(string &a, string &b, int i, int j, vector<vector<int>> &dp) {
        if (i == 0) return j;
        if (j == 0) return i;
        if (dp[i][j] != -1) return dp[i][j];
    
        if (a[i - 1] == b[j - 1])
            return dp[i][j] = 1 + helper(a, b, i - 1, j - 1, dp);
    
        return dp[i][j] = 1 + min(helper(a, b, i - 1, j, dp),
                                  helper(a, b, i, j - 1, dp));
    }

    int minSuperSeq(string &s1, string &s2) {
        // code here
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        
        return helper(s1, s2, m, n, dp);
    }
};
