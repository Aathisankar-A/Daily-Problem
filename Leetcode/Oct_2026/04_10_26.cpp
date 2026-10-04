class Solution {
public boolean checkValidString(String s) {
        int n = s.length();

        int mnOpen = 0;
        int mxOpen = 0;

        for(char ch : s.toCharArray()){
            if(ch == '('){
                mxOpen++;
                mnOpen++;
            }
            else if(ch == ')'){
                mxOpen--;
                mnOpen--;
            }
            else{
                mnOpen--;
                mxOpen++;
            }
            if(mxOpen < 0)
                return false;
            
            mnOpen = Math.max(0, mnOpen);
        }
        
        return mnOpen == 0;
    }
};
