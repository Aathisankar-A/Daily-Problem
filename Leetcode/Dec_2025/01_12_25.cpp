class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = reduce(batteries.begin(), batteries.end(), 0LL);
        long long l = *min_element(batteries.begin(), batteries.end());
        long long r = sum / n;
        long long res = 0;

        while(l <= r){
            long long mid = (l + r) >> 1;
            long long reserve = 0;

            for(int x : batteries)
                reserve += min((long long)x, mid);

            if(reserve >= mid * n){
                res = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }

        return res;
    }
};
