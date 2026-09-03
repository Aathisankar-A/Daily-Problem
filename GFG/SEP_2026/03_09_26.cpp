class Solution {
  public:
    int solve(int i, int prev, vector<int>& arr, vector<vector<int>>& dp){

        if(i == arr.size()){
            return 0;
        }

        if(dp[i][prev] != -1){
            return dp[i][prev];
        }

        int pick = abs(arr[i] - prev) + solve(i+1, arr[i], arr, dp);

        int notPick = abs(prev - 1) + solve(i+1, 1, arr, dp);

        return dp[i][prev] = max(pick, notPick);


    }
    int maxDiffSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        int mx = *max_element(begin(arr), end(arr));

        vector<vector<int>>dp (n+1, vector<int>(mx+1, -1));
        
        int pick = solve(1, arr[0], arr, dp);
        
        dp = vector<vector<int>>(n+1, vector<int>(mx+1, -1));
        
        int notPick = solve(1, 1, arr, dp);

        return max(pick, notPick);
    }
};
