class Solution {
public:
    bool isSorted(vector<int> &nums, int n) {
        for(int i = 1; i < n; i++){
            if(nums[i] < nums[i - 1]) return false;
        }
        return true;
    }
    
    int minimumPairRemoval(vector<int> &nums) {
        int count = 0;
        int n = nums.size();

        while(!isSorted(nums, n)){
            int minSum = INT_MAX;
            int targetIndex = -1;

            for(int i = 1; i < n; i++){
                int sum = nums[i - 1] + nums[i];
                if(sum < minSum){
                    minSum = sum;
                    targetIndex = i;
                }
            }
            nums[targetIndex - 1] = minSum;
            for(int i = targetIndex; i < n - 1; i++){
                nums[i] = nums[i + 1];
            }
            n--;
            count++;
        }
        return count;
    }
};
