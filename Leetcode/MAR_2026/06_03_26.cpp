class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();

        if(n == 1)
            return true;

        bool flag = false;
        
        for(int i = 1; i < n; i++){
            if(s[i] == '0'){
                flag = true;
                continue;
            }
            else{
                if(flag == true){
                    return false;
                }
            }
        }
        return true;
    }
};
