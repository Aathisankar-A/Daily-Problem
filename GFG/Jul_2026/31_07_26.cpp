class Solution {
  public:
    int countSubsets(vector<int> &arr) {
        // code here
        const int mod = 1000000007;

        vector<int> p = {2,3,5,7,11,13,17,19,23,29};
        vector<int> cnt(31,0);

        for(int x : arr)
            cnt[x]++;

        vector<int> mask(31,-1);

        for(int i = 2; i <= 30; i++){
            int x = i;
            int m = 0;
            bool ok = true;

            for(int j = 0; j < 10; j++){
                int c = 0;
                while(x % p[j] == 0){
                    x /= p[j];
                    c++;
                }

                if(c > 1){
                    ok = false;
                    break;
                }

                if(c == 1)
                    m |= (1 << j);
            }

            if(ok)
                mask[i] = m;
        }

        vector<long long> dp(1 << 10,0);
        dp[0] = 1;

        for(int i = 2; i <= 30; i++){
            if(cnt[i] == 0 || mask[i] == -1)
                continue;

            for(int s = (1 << 10) - 1; s >= 0; s--){
                if((s & mask[i]) == 0){
                    dp[s | mask[i]] =
                    (dp[s | mask[i]] + dp[s] * 1LL * cnt[i]) % mod;
                }
            }
        }

        long long ans = 0;

        for(int s = 1; s < (1 << 10); s++)
            ans = (ans + dp[s]) % mod;

        long long pw = 1;

        for(int i = 0; i < cnt[1]; i++)
            pw = (pw * 2) % mod;

        ans = (ans * pw) % mod;

        return ans;
    }
};
