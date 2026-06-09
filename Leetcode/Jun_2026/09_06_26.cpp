class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        int mn = nums[0];
        int mx = nums[0];

        for(int i = 1; i < n; i++){
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }

        return 1LL * k * (mx - mn);
    }
};
