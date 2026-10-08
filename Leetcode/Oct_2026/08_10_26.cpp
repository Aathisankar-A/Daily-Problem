class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        string res = "";

        for(char& i : s){
            if(i == '(' && cnt++ > 0)  res += i;
            else if(i == ')' && cnt-- > 1)  res += i;
        }
        return res;
    }
};
