class Solution {
  public:
    int countFriendsPairings(int n) {
        // code here
        if(n <= 2){
            return n;
        }

        int a = 1;
        int b = 2;

        for(int i = 3; i <= n; i++){
            int c = b + 1LL * (i - 1) * a;
            a = b;
            b = c;
        }

        return b;
    }
};
