class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int M = 2048;

        vector<vector<int>> dp(4, vector<int>(M, 0));
        dp[0][0] = 1;

        for(int v : nums){
            vector<vector<int>> nd = dp;

            for(int x = 0; x < M; x++){
                if(dp[0][x]){
                    nd[1][x ^ v] = 1;
                    nd[2][x] = 1;
                    nd[3][x ^ v] = 1;
                }

                if(dp[1][x]){
                    nd[2][x ^ v] = 1;
                    nd[3][x] = 1;
                }

                if(dp[2][x]){
                    nd[3][x ^ v] = 1;
                }
            }

            dp = nd;
        }

        int ans = 0;
        for(int x = 0; x < M; x++)
            if(dp[3][x])
                ans++;

        return ans;
    }
};
