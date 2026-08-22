class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, pro = 1;
        int org = n;

        while(n > 0){
            int d = n % 10;
            n /= 10;

            sum += d;
            pro *= d;
        }

        return org % (sum + pro) == 0;
    }
};
