class Solution {
public:
    bool checkString(string s) {
        int n = s.size();

        int b = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'b' && b == 0){
                b = 1;
            }

            if(s[i] == 'a'){
                if(b == 1){
                    return false;
                }
            }
        }
        return true;
    }
};
