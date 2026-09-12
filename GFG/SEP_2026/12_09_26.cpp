class Solution {
  public:
    int maxProduct(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        long long INF = 1e18;

        vector<long long> mx(k + 1, -INF);
        vector<long long> mn(k + 1, INF);

        mx[0] = mn[0] = 1;

        for(int x : arr){
            for(int j = min(k, n); j >= 1; j--){
                if(mx[j - 1] == -INF && mn[j - 1] == INF){
                    continue;
                }

                long long a = mx[j - 1] * x;
                long long b = mn[j - 1] * x;

                mx[j] = max({mx[j], a, b});
                mn[j] = min({mn[j], a, b});
            }
        }

        return mx[k];
    }
};
