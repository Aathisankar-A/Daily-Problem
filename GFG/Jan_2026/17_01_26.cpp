class Solution {
  public:
    bool checkRedundancy(string &s) {
        stack<char> st;
        for(char c : s){
            if(c == ')'){
                bool hasOp = false;
                while(!st.empty() && st.top() != '('){
                    char t = st.top();
                    st.pop();
                    if(t == '+' || t == '-' || t == '*' || t == '/')
                        hasOp = true;
                }
                if(!hasOp) return true;
                if(!st.empty()) st.pop();
            }
            else{
                st.push(c);
            }
        }
        return false;
    }
};
