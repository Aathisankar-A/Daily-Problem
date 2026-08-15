class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;
        bool allZero = true;

        for(int x : nums){
            xr ^= x;

            if(x > 0){
                allZero = false;
            }
        }

        if(xr > 0){
            return n;
        }

        if(allZero){
            return 0;
        }

        return n - 1;
    }
};
