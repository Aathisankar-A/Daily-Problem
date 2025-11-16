class Solution {
  public:
    int minCutCost(int n, vector<int> &cuts) {
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());

    int sz = cuts.size();
    vector<vector<int>> dp(sz, vector<int>(sz, 0));

    for (int len = 2; len < sz; len++) {
        for (int left = 0; left + len < sz; left++) {
            int right = left + len;
            int minCost = INT_MAX;

            for (int i = left + 1; i < right; i++) {
                int cost = cuts[right] - cuts[left] + dp[left][i] + dp[i][right];
                minCost = min(minCost, cost);
            }

            dp[left][right] = (minCost == INT_MAX) ? 0 : minCost;
        }
    }

    return dp[0][sz - 1];
}
};
