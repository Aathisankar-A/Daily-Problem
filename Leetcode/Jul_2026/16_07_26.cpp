class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN;

        for(int i = 0; i < n; i++){
            mx = max(mx, nums[i]);

            nums[i] = gcd(nums[i], mx);
        }

        sort(nums.begin(), nums.end());

        int i = 0;
        int j = n-1;

        long long sum = 0;

        while(i < j){
            sum = sum + gcd(nums[i], nums[j]);

            i++;
            j--;
        }

        return sum;
    }
};
