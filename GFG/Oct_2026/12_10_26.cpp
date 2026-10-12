class Solution {
  public:
    int minSquares(int n, int m) {
        // code here
        int res = 0;

        while(n && m){
            if(n < m){
                swap(n, m);
            }

            res += n / m;
            n %= m;
        }

        return res;
    }
};
