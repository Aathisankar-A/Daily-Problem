class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n = arr.size();
        
        int total = 0;
        for(int x : arr)
            total += x;
        
        // invalid cases
        if(total < diff || (total + diff) % 2 != 0)
            return 0;
        
        int target = (total + diff) / 2;
        
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        
        for(int i = 0; i < n; i++){
            for(int j = target; j >= arr[i]; j--){
                dp[j] += dp[j - arr[i]];
            }
        }
        
        return dp[target];
    }
};
