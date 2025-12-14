class Solution {
public:
    int MOD = 1000000007;

    int helper(int i, int seats, string &cor, vector<vector<int>> &dp){
        if(i == cor.size()){
            if(seats == 2)
                return 1;
            return 0;
        }

        if(dp[i][seats] != -1){
            return dp[i][seats];
        }

        int res = 0;

        if(seats == 2){
            if(cor[i] == 'S')
                res = helper(i + 1, 1, cor, dp);
            else
                res = (helper(i + 1, 0, cor, dp) + helper(i + 1, seats, cor, dp)) % MOD;
        }
        else{
            if(cor[i] == 'S')
                res = helper(i + 1, seats + 1, cor, dp);
            else
                res = helper(i + 1, seats, cor, dp);
        }

        dp[i][seats] = res;
        return dp[i][seats];
    }

    int numberOfWays(string corridor) {
        int n = corridor.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return helper(0, 0, corridor, dp);
    }
};
