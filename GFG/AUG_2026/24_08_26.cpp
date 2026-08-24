class Solution {
  public:
    const int mod = 1e9 + 7;

    long long power(long long a, long long b){
        long long ans = 1;

        while(b > 0){
            if(b % 2 == 1){
                ans = ans * a % mod;
            }

            a = a * a % mod;
            b /= 2;
        }

        return ans;
    }

    int prefixStrings(int n) {
        // code here
        vector<long long> fact(2 * n + 1);

        fact[0] = 1;

        for(int i = 1; i <= 2 * n; i++){
            fact[i] = fact[i - 1] * i % mod;
        }

        long long ans = fact[2 * n];

        ans = ans * power(fact[n], mod - 2) % mod;
        ans = ans * power(fact[n], mod - 2) % mod;
        ans = ans * power(n + 1, mod - 2) % mod;

        return ans;
    }
};
