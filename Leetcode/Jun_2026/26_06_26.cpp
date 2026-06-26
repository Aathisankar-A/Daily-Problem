class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int pre = n;

        vector<int> f(2 * n + 1, 0);
        f[n] = 1;

        long long less = 0;
        long long ans = 0;

        for(int x : nums){
            if(x == target){
                less += f[pre];
                pre++;
            }
            else{
                pre--;
                less -= f[pre];
            }

            f[pre]++;
            ans += less;
        }

        return ans;
    }
};
