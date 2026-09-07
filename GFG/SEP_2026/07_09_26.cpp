class Solution {
  public:
    int minCount(vector<int>& arr) {
        // code here
        int n = arr.size();

        vector<vector<int>> dp(102, vector<int>(102, -1));
        dp[0][101] = 0;

        for(int x : arr){
            vector<vector<int>> ndp = dp;

            for(int i = 0; i <= 100; i++){
                for(int d = 1; d <= 101; d++){
                    if(dp[i][d] == -1){
                        continue;
                    }

                    if(x > i){
                        ndp[x][d] = max(ndp[x][d], dp[i][d] + 1);
                    }

                    if(x < d){
                        ndp[i][x] = max(ndp[i][x], dp[i][d] + 1);
                    }
                }
            }

            dp = ndp;
        }

        int mx = 0;

        for(int i = 0; i <= 100; i++){
            for(int d = 1; d <= 101; d++){
                mx = max(mx, dp[i][d]);
            }
        }

        return n - mx;
    }
};
