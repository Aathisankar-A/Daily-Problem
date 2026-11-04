class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> low, high;
        long long s1 = 0, s2 = 0;

        auto balance = [&](){
            int need = (x + 1) / 2;

            while(low.size() > need){
                int v = *low.rbegin();
                low.erase(prev(low.end()));
                s1 -= v;
                high.insert(v);
                s2 += v;
            }

            while(low.size() < need && !high.empty()){
                int v = *high.begin();
                high.erase(high.begin());
                s2 -= v;
                low.insert(v);
                s1 += v;
            }
        };

        auto add = [&](int v){
            if(low.empty() || v <= *low.rbegin()){
                low.insert(v);
                s1 += v;
            }
            else{
                high.insert(v);
                s2 += v;
            }
            balance();
        };

        auto remove = [&](int v){
            auto it = low.find(v);

            if(it != low.end()){
                low.erase(it);
                s1 -= v;
            }
            else{
                it = high.find(v);
                high.erase(it);
                s2 -= v;
            }

            balance();
        };

        auto getCost = [&](){
            long long med = *low.rbegin();

            return med * low.size() - s1 +
                   s2 - med * high.size();
        };

        vector<long long> cost(n - x + 1);

        for(int i = 0; i < x; i++){
            add(nums[i]);
        }

        cost[0] = getCost();

        for(int i = x; i < n; i++){
            add(nums[i]);
            remove(nums[i - x]);
            cost[i - x + 1] = getCost();
        }

        const long long INF = 4e18;

        vector<vector<long long>> dp(k + 1,
                                     vector<long long>(n + 1, INF));

        for(int i = 0; i <= n; i++){
            dp[0][i] = 0;
        }

        for(int j = 1; j <= k; j++){
            for(int i = 1; i <= n; i++){
                dp[j][i] = dp[j][i - 1];

                if(i >= x && dp[j - 1][i - x] != INF){
                    dp[j][i] = min(dp[j][i],
                                   dp[j - 1][i - x] + cost[i - x]);
                }
            }
        }

        return dp[k][n];
    }
};
