class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int mx = nums[0];

        for(int i = 1; i < n; i++){
            ans = max(ans, (mx - 1) * (nums[i] - 1));
            mx = max(mx, nums[i]);
        }

        return ans;
    }
};
