class Solution {
  public:
    bool helper(string &s1, string &s2, string &s3, int i, int j, vector<vector<int>> &dp){
        if(i == s1.size() && j == s2.size())
            return 1;
            
        if(dp[i][j] != -1)
            return dp[i][j];
            
        int k = i + j;
        
        bool a = (i < s1.size() && s1[i] == s3[k] && helper(s1, s2, s3, i + 1, j, dp));
        bool b = (j < s2.size() && s2[j] == s3[k] && helper(s1, s2, s3, i, j + 1, dp));
        
        return dp[i][j] = (a || b);
    }
    
    bool isInterleave(string &s1, string &s2, string &s3) {
        // code here
        if (s1.size() + s2.size() != s3.size())
            return 0;
        
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        
        return helper(s1, s2, s3, 0, 0, dp);
    }
};
