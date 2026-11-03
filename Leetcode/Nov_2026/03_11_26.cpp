class Solution {
public:
    int minMoves(vector<int>& nums) {
         int mx = nums[0];

        for(int a : nums){
            mx = max(mx, a);
        }
          int res = 0;

        for(int a : nums){           
            res += mx-a;
        }

        return res;
    }
};
