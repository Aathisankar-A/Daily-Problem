class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        
        int prev = 0;
        int curr = 1;
        int res = 0;

        for(int i = 1; i < n; i++){
            if(s[i] == s[i - 1]){
                curr++;
            }
            else{
                res += min(prev, curr);
                prev = curr;
                curr = 1;
            }
        }

        res += min(prev, curr);
        return res;
    }
};
