class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> free(n, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j && items[j][0] % items[i][0] == 0){
                    free[i]++;
                }
            }
        }

        vector<int> dp(budget + 1, 0);

        for(int i = 0; i < n; i++){
            int p = items[i][1];
            int bonus = free[i];

            vector<int> cur(budget + 1, -1e9);
            vector<int> ndp = dp;

            for(int b = p; b <= budget; b++){
                cur[b] = dp[b - p] + bonus + 1;

                if(cur[b - p] != -1e9){
                    cur[b] = max(cur[b], cur[b - p] + 1);
                }

                ndp[b] = max(ndp[b], cur[b]);
            }

            dp = ndp;
        }

        return dp[budget];
    }
};
