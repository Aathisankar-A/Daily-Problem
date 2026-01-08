class Solution {
public:
    int n, m;

    int helper(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp){
        if(i == n || j == m)
            return INT_MIN;

        if(dp[i][j] != -1)
            return dp[i][j];
        
        int take = nums1[i] * nums2[j] + max(0, helper(i+1, j+1, nums1, nums2, dp));

        int skip1 = helper(i+1, j, nums1, nums2, dp);
        int skip2 = helper(i, j+1, nums1, nums2, dp);
        
        dp[i][j] = max({take, skip1, skip2});
        return dp[i][j];
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();
        vector<vector<int>> dp(501, vector<int>(501, -1));

        return helper(0, 0, nums1, nums2, dp);
    }
};
