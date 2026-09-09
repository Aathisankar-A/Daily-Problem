class Solution {
public:
    long long countCommas(long long n) {
        long long res = 0;

        long long st = 1000;
        int comma = 1;

        while(st <= n){
            long long end = st * 1000 - 1;
            long long cnt = min(n, end) - st + 1;

            if(cnt > 0)
                res += cnt * comma;

            st *= 1000;
            comma++;
        }
        return res;
    }
};
