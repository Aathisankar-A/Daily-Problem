class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();

        int cnt = 0;
        int res = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                cnt++;
            }
            else if(i > 0 && s[i-1] == '1'){
                res += cnt;
            }
        }
        return res;
    }
};
