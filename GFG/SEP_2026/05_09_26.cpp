class Solution {
  public:
    int longestSubseq(vector<int>& arr) {
        // code here
        unordered_map<int,int> dp;
        int ans = 1;

        for(int x : arr){
            int cur = max(dp[x - 1], dp[x + 1]) + 1;
            dp[x] = max(dp[x], cur);
            ans = max(ans, dp[x]);
        }

        return ans;
    }
};
