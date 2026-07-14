class Solution {
public:
    int dp[201][201][201];
    vector<int> v;
    int n;
    const int mod = 1e9 + 7;

    int solve(int i,int g1,int g2){
        if(i == n){
            if(g1 > 0 && g2 > 0 && g1 == g2) return 1;
            return 0;
        }

        if(dp[i][g1][g2] != -1) return dp[i][g1][g2];

        int ans = 0;

        ans = solve(i + 1,g1,g2);
        ans = (ans + solve(i + 1,std::gcd(g1,v[i]),g2)) % mod;
        ans = (ans + solve(i + 1,g1,std::gcd(g2,v[i]))) % mod;

        return dp[i][g1][g2] = ans;
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));

        v = nums;
        n = nums.size();

        return solve(0,0,0);
    }
};
