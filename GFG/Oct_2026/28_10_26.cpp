class Solution {
  public:
    char nthCharacter(int n) {
        // code here
        long long len = 1, cnt = 9, start = 1;

        while(n > len * cnt){
            n -= len * cnt;
            len++;
            cnt *= 10;
            start *= 10;
        }

        long long num = start + (n - 1) / len;
        int idx = (n - 1) % len;

        return to_string(num)[idx];
    }
};
