class Solution {
  public:
    bool wildCard(string &txt, string &pat) {
        // code here
        int n = txt.size();
        int m = pat.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;

        for(int i = 0; i <= n; i++){
            for(int j = 1; j <= m; j++){

                if(i == 0){
                    dp[i][j] = ((j > 0) ? dp[i][j - 1] : true) && (pat[j - 1] == '*');
                } 

                else if(pat[j - 1] == '?' || txt[i - 1] == pat[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                } 
                else if(pat[j - 1] == '*'){
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }
        return dp[n][m];
    }
};
