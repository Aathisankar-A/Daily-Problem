class Solution {
  public:
    int LCIS(vector<int> &a, vector<int> &b) {
        //code here
        int m = a.size(), n = b.size();
        vector<int> dp(n, 0);
    
        for(int i = 0; i < m; i++){
            int cur = 0;
            for(int j = 0; j < n; j++){
                if(a[i] == b[j]){
                    dp[j] = max(dp[j], cur + 1);
                }
                else if(a[i] > b[j]){
                    cur = max(cur, dp[j]);
                }
            }
        }
    
        return *max_element(dp.begin(), dp.end());
    }


};
