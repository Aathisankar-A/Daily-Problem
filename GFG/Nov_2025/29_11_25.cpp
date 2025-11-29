class Solution {
  public:
    int countSetBits(int n) {
        // code here
        if (n == 0)
            return 0;

        int x = log2(n);
        
        int fullBits = x * (1 << (x - 1));
    
        int msbBits = n - (1 << x) + 1;
    
        int rem = n - (1 << x);
        int remBits = countSetBits(rem);
    
        return fullBits + msbBits + remBits;
    }
};
