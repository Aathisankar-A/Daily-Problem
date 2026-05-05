class Solution {
  public:
    int findPosition(int n) {
        // code here
        if(n == 0) return -1;

        if((n & (n - 1)) != 0) return -1;

        int pos = 1;

        while(n > 1){
            n = n >> 1;
            pos++;
        }

        return pos;
    }
};
