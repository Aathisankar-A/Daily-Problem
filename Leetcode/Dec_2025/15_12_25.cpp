class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();

        if(n == 1) return 1;

        int cnt = 1;
        long long res = 0;

        for(int i = 1; i < n; i++){
            if(prices[i - 1] - prices[i] == 1){
                cnt++;
            }
            else{
                res += (long long)cnt * (cnt + 1) / 2;
                cnt = 1;
            }
        }

        res += (long long)cnt * (cnt + 1) / 2;
        return res;
    }
};
