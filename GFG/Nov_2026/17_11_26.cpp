class Solution {
  public:
    bool findPattern(string& s) {
        // code here
        int x = 0, y = 0;

        for(char c : s){
            if(c == 'x'){
                if(y > 0){
                    if(x != y) return false;

                    x = 0;
                    y = 0;
                }

                x++;
            }
            else{
                if(x == 0) return false;

                y++;
                if(y > x) return false;
            }
        }

        return x == y && x > 0;
    }
};
