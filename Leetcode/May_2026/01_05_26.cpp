class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        
        long sum = 0;
        long curr = 0;
        
        for(int i = 0; i < n; i++){
            sum += nums[i];
            curr += (long)i * nums[i];
        }
        
        long maxi = curr;
        
        for(int i = n - 1; i >= 0; i--){
            curr = curr + sum - (long)n * nums[i];
            
            maxi = max(maxi, curr);
        }
        
        return (int)maxi;
    }
};
