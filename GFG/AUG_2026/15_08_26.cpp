class Solution {
  public:
    int countWithout(int n, int d) {
        // code here
        string s = to_string(n);

        long long dp[2][2] = {};
        dp[1][0] = 1;

        for(char c : s){
            long long ndp[2][2] = {};

            for(int tight = 0; tight <= 1; tight++){
                for(int started = 0; started <= 1; started++){
                    if(dp[tight][started] == 0) continue;

                    int limit = tight ? c - '0' : 9;

                    for(int x = 0; x <= limit; x++){
                        int ns = started || x != 0;

                        if(ns && x == d) continue;

                        int nt = tight && (x == limit);

                        ndp[nt][ns] += dp[tight][started];
                    }
                }
            }

            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 2; j++){
                    dp[i][j] = ndp[i][j];
                }
            }
        }

        return dp[0][1] + dp[1][1];
    }
};
