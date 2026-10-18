class Solution {
public:
    const int mod = 1e9 + 7;
    vector<vector<long long>> dp;

    int solve(vector<int>& nums){
        int n = nums.size();

        if(n <= 2)
            return 1;

        vector<int> left, right;

        for(int i = 1; i < n; i++){
            if(nums[i] < nums[0])
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        long long l = solve(left);
        long long r = solve(right);

        return dp[n - 1][left.size()] * l % mod * r % mod;
    }
    
    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        dp.assign(n, vector<long long>(n, 0));

        for(int i = 0; i < n; i++){
            dp[i][0] = dp[i][i] = 1;
        }

        for(int i = 2; i < n; i++){
            for(int j = 1; j < i; j++){
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
            }
        }

        return (solve(nums) - 1 + mod) % mod;
    }
};
