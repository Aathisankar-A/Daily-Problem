class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        
        int total = 0;
        for(int num : nums)
            total += num;

        int left = 0;
        int count = 0;

        for(int i = 0; i < n-1; i++){
            left += nums[i];
            int right = total - left;

            if((left % 2) == (right % 2))
                count++;
        }
        return count;
    }
};
