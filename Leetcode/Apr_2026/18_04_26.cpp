class Solution {
public:
    int mirrorDistance(int n) {
        int rev = 0;
        int t = n;

        while(n){
            int dig = n % 10;
            rev = rev * 10 + dig;
            n /= 10;
        }

        return abs(rev - t);
    }
};
