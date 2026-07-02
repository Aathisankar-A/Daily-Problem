class Solution {
  public:
    bool divisibleByK(vector<int>& arr, int k) {
        // code here
        vector<bool> dp(k, false);
        
        for(int num : arr){
            
            vector<bool> curr = dp;
            
            curr[num % k] = true;
            
            for(int rem = 0; rem < k; rem++){
                
                if(!dp[rem]){
                    continue;
                }
                
                curr[(rem + num) % k] = true;
            }
            
            dp = curr;
            
            if(dp[0]){
                return true;
            }
        }
        
        return false;
    }
};
