class Solution {
public:
    long long sumAndMultiply(int n) {
        int x = 0;
        
        int sum = 0;

        while(n){
            if(n%10 != 0)
                x = x * 10 + (n % 10);
            sum += n % 10;
            n /= 10;
        }

        int x2 = 0;

        while(x){
            x2 = x2 * 10 + (x % 10);
            x /= 10;
        }

        return (long long)x2 * sum;
    }
};
