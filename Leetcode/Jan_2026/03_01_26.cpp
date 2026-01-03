class Solution {
public:
    int numOfWays(int n) {
        int MOD = 1e9 + 7;
        long long same = 6;
        long long diff = 6;

        for(int i = 1; i < n; i++){
            long long ns = (same * 3 + diff * 2) % MOD;
            long long nd = (same * 2 + diff * 2) % MOD;

            same = ns;
            diff = nd;
        }
        return (same + diff) % MOD;
    }
};
