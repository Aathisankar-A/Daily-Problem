class Solution {
  public:
    int totalWays(vector<int>& arr, int target) {
        //  code here
        int n = arr.size();
        
        int sum = 0;
        for(int x : arr){
            sum += x;
        }
        
        if((sum + target) % 2 != 0 || sum < abs(target)){
            return 0;
        }
        
        int s2 = (sum + target) / 2;
        
        vector<int>dp(s2 + 1, 0);
        dp[0] = 1;
        
        for(int i = 0; i < n; i++){
            for(int j = s2; j >= arr[i]; j--){
                dp[j] += dp[j - arr[i]];
            }
        }
        
        return dp[s2];
    }
};
