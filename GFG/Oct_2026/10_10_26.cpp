class Solution {
  public:
    bool balancePan(int a, int b) {
        // code here
        if(a <= 0 || b < 0) return false;
        if(a == 1) return true;

        while(b){
            int r = b % a;

            if(r == 0){
                b /= a;
            }
            else if(r == 1){
                b = (b - 1) / a;
            }
            else if(r == a - 1){
                b = (b + 1) / a;
            }
            else{
                return false;
            }
        }

        return true;
    }
};
