class Solution {
  public:
    int countMinOperations(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        vector<int> nums = arr;
        int ans = 0;
        
        while(true){
            bool allZ = true;
            
            for(int x : nums){
                if(x != 0){
                    allZ = false;
                    break;
                }
            }
            
            if(allZ){
                return ans;
            }
            
            for(int i = 0; i < n; i++){
                if(nums[i] % 2){
                    ans++;
                    nums[i]--;
                }
            }
            
            bool hasNonZ = false;
            
            for(int x : nums){
                if(x > 0){
                    hasNonZ = true;
                    break;
                }
            }
            
            if(hasNonZ){
                for(int i = 0; i < n; i++){
                    nums[i] = nums[i] / 2;
                }
                ans++;
            }
        }
        return ans;
    }
};
