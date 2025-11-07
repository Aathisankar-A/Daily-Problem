class Solution {
  public:
    int nxtJob(vector<vector<int>> &a, int i) {
        int l = i + 1, r = a.size() - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (a[m][0] >= a[i][1]) r = m - 1;
            else l = m + 1;
        }
        return l;
    }

    int helper(int i, vector<vector<int>> &a, vector<int> &dp) {
        if (i >= a.size()) return 0;
        if (dp[i] != -1) return dp[i];
    
        int skip = helper(i + 1, a, dp);
        int j = nxtJob(a, i);
        int take = a[i][2] + helper(j, a, dp);
    
        return dp[i] = max(take, skip);
    }
    
    int maxProfit(vector<vector<int>> &jobs) {
        // code here
        sort(jobs.begin(), jobs.end());
        int n = jobs.size();
        vector<int> dp(n, -1);
        return helper(0, jobs, dp);
    }
};
