class Solution {
  public:
    int findIndex(string &s) {
        // code here
        int n = s.size();

        int rightClose = 0;
        for(char ch : s){
            if(ch == ')')
                rightClose++;
        }

        int leftOpen = 0;

        for(int k = 0; k < n; k++){
            if(leftOpen == rightClose)
                return k;

            if(s[k] == '(')
                leftOpen++;
            else
                rightClose--;
        }

        if(leftOpen == rightClose)
            return n;

        return -1;
    }
};
