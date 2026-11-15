class Solution {
  public:
    int subsequenceSum(string &s) {
        // code here
        long long mod = 1e9 + 7;
        long long sum = 0;

        for(char c : s){
            sum = (sum + (c - '0')) % mod;
        }

        long long p = 1;

        for(int i = 0; i < s.size() - 1; i++){
            p = (p * 2) % mod;
        }

        return (sum * p) % mod;
    }
};
