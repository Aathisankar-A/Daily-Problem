class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int tot = accumulate(nums.begin(), nums.end(), 0);
        int tar = tot - x;

        if(tar < 0) return -1;
        if(tar == 0) return n;

        int l = 0, sum = 0, mx = -1;

        for(int r = 0; r < n; r++){
            sum += nums[r];

            while(l <= r && sum > tar){
                sum -= nums[l++];
            }

            if(sum == tar){
                mx = max(mx, r - l + 1);
            }
        }

        return mx == -1 ? -1 : n - mx;
    }
};
