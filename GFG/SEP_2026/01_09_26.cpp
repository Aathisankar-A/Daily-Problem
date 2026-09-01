class Solution {
  public:
    int palindromicStrings(int n, int k) {
        // code here
        const int mod = 1e9 + 7;
        long long ans = 0;
        long long p = 1;

        for(int h = 1; 2 * h - 1 <= n; h++){
            p = p * (k - h + 1) % mod;

            ans = (ans + p) % mod;

            if(2 * h <= n)
                ans = (ans + p) % mod;
        }

        return ans;
    }
};
