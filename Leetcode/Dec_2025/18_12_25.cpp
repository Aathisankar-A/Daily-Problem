class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();

        long long base = 0;
        for(int i = 0; i < n; i++){
            base += 1LL * strategy[i] * prices[i];
        }

        vector<long long> pl(n + 1, 0), pg(n + 1, 0);

        for(int i = 0; i < n; i++){
            pl[i + 1] = pl[i] + 1LL * strategy[i] * prices[i];
            pg[i + 1] = pg[i] + 1LL * (1 - strategy[i]) * prices[i];
        }

        long long best = 0;
        int h = k / 2;

        for(int l = 0; l <= n-k; l++){
            int m = l + h;
            int r = l + k;

            long long cur = -(pl[m] - pl[l]) + (pg[r] - pg[m]);

            best = max(best, cur);
        }
        return base + best;
    }
};
