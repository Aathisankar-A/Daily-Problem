class Solution {
  public:
    int countBT(int h) {
        // code here
        const long long MOD = 1e9 + 7;

        if(h == 0) return 1;
        if(h == 1) return 1;

        long long a = 1;
        long long b = 1;

        for(int i = 2; i <= h; i++){
            long long c = (b * b + 2 * b * a) % MOD;

            a = b;
            b = c;
        }

        return b;
    }
};
