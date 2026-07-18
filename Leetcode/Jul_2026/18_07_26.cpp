class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();

        int mn = nums[0];
        int mx = nums[0];

        for(int i = 1; i < n; i++){
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }

        return gcd(mx, mn);
    }
};
