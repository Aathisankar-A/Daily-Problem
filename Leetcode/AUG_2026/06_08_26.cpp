class Solution {
public:
    int smallestNumber(int n, int t) {
        if(n == 100)
            return n;

        for(int i = n; i < n+10; i++){
            int p;

            if(i < 10){
                p = i;
            }
            else{
                p = (i / 10) * (i % 10);
            }

            if(p%t == 0){
                return i;
            }
        }
        return n;
    }
};
