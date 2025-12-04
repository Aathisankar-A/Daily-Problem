class Solution {
  public:
    int sum(vector<int> &freq, int i, int j){
        int s = 0;
        for(int k = i; k <= j; k++) s += freq[k];
        return s;
    }

    int optCost(vector<int> &freq, int i, int j, vector<vector<int>> &dp){
        if(j < i) return 0;
        if(j == i) return freq[i];
        
        if(dp[i][j] != -1) return dp[i][j];
    
        int fsum = sum(freq, i, j);
        int minCost = INT_MAX;
    
        for(int r = i; r <= j; r++){
            int cost = optCost(freq, i, r - 1, dp) + optCost(freq, r + 1, j, dp);
            if(cost < minCost) minCost = cost;
        }
    
        return dp[i][j] = minCost + fsum;
    }

    int minCost(vector<int> &keys, vector<int> &freq) {
        // code here
        int n = keys.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return optCost(freq, 0, n - 1, dp);
    }
};
