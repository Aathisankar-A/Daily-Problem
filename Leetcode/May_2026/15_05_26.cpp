class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int l = 0;
        int r = n-1;

        int mid;
        int ans;

        while(l < r){
            mid = (l+r) / 2;

            if(nums[mid] > nums[r]){
                l = mid+1;
                ans = nums[r];
            }
            else{
                r = mid;
                ans = nums[mid];
            }
        }
        return ans;
    }
};
