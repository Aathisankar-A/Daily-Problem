class Solution {
  public:
    string removeKdig(string &s, int k) {
        // code here
        string st;

        for(char c : s){
            while(!st.empty() && k > 0 && st.back() > c){
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }

        while(k > 0 && !st.empty()){
            st.pop_back();
            k--;
        }

        int idx = 0;
        while(idx < st.size() && st[idx] == '0')
            idx++;

        string res = st.substr(idx);

        if(res.empty())
            return "0";

        return res;
    }
};
