class Solution {
  public:
    bool isBinaryPalindrome(int n) {
        // code here
        int original = n;
        int reversed = 0;
        
        while(n > 0){
            reversed = (reversed << 1) | (n & 1);
            n = n >> 1;
        }
        
        return original == reversed;
    }
};
