class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;

        unordered_map<int, int> suffix;
        unordered_map<int, int> prefix;

        for(auto x : nums)
            suffix[x] += 1;

        long long res = 0;

        for(auto x : nums){
            suffix[x] -= 1;
            res += (long long)prefix[2 * x] * suffix[2 * x];
            prefix[x] += 1;
        }
        return res % MOD;
    }
};
