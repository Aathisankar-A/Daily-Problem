class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        int res = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                nums.push_back(grid[i][j]);
            }
        }

        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + n/2, nums.end());
        int t = nums[n/2];

        for(int num : nums){
            if(num % x != t % x)
                return -1;
            
            res += abs(t - num) / x;
        }
        return res;
    }
};
