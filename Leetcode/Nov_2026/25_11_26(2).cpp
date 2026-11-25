class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        long long mod1 = 1e9 + 7;
        long long mod2 = 1e9 + 9;
        long long base = 37;

        vector<long long> h1(n + 1, 0), h2(n + 1, 0);
        vector<long long> p1(n + 1, 1), p2(n + 1, 1);

        for(int i = 0; i < n; i++){
            h1[i + 1] = (h1[i] * base + nums[i]) % mod1;
            h2[i + 1] = (h2[i] * base + nums[i]) % mod2;

            p1[i + 1] = (p1[i] * base) % mod1;
            p2[i + 1] = (p2[i] * base) % mod2;
        }

        auto check = [&](int k){
            map<pair<long long, long long>, int> mp;

            for(int i = 0; i + k <= n; i++){
                long long x = (h1[i + k] - h1[i] * p1[k] % mod1 + mod1) % mod1;
                long long y = (h2[i + k] - h2[i] * p2[k] % mod2 + mod2) % mod2;

                mp[{x, y}]++;
            }

            for(auto &it : mp){
                if(it.second == 1) return true;
            }

            return false;
        };

        int low = 1, high = n;
        int ans = n;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(check(mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};
