class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;

        for(int i = 0; i < n >> 1; i++)
            res = max(res, nums[n - 1 - i] + nums[i]);

        return res;
    }
};
