class Solution {
  public:
    int minCost(vector<vector<int>> &costs) {
        // code here
        int n = costs.size();
        int k = costs[0].size();
        
        if(n == 0)
            return 0;
        
        if(k == 1) 
            return n == 1 ? costs[0][0] : -1;
    
        vector<int> dp(k);
        
        for(int j = 0; j < k; j++)
            dp[j] = costs[0][j];
    
        for(int i = 1; i < n; i++){
            int mn1 = INT_MAX, mn2 = INT_MAX;
            int c1 = -1;
    
            for(int j = 0; j < k; j++){
                if(dp[j] < mn1){
                    mn2 = mn1;
                    mn1 = dp[j];
                    c1 = j;
                }
                else if(dp[j] < mn2){
                    mn2 = dp[j];
                }
            }
    
            vector<int> ndp(k);
            for(int j = 0; j < k; j++){
                int best = (j == c1 ? mn2 : mn1);
                ndp[j] = best + costs[i][j];
            }
            dp = ndp;
        }
    
        int res = *min_element(dp.begin(), dp.end());
        return res;
    }
};
