class Solution {
public:
    int maxProduct(int n) {
        int max1 =INT_MIN;
        int max2 =INT_MIN;
        
        while(n > 0){
           int curr = n % 10;
           if(curr > max1){
            max2  = max1;
            max1 = curr;
           }
            else if(curr > max2){
                max2 = curr;
            }
              n /= 10;
        }

         return max1 * max2;
    }
};
