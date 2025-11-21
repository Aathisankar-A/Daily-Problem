class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();

        unordered_set<char> st;
        for(char c : s){
            st.insert(c);
        }

        int res = 0;

        for(char c : st){
            int i = -1, j = 0;

            for(int k = 0; k < n; k++){
                if(s[k] == c){
                    if(i == -1){
                        i = k;
                    }
                    j = k;
                }
            }

            unordered_set<char> pst;
            for(int k = i + 1; k < j; k++){
                pst.insert(s[k]);
            }

            res += pst.size();
        }
        return res;
    }
};
