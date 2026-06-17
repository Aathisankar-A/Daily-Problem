class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();

        vector<long long> len(n);

        long long currLen = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '*'){
                currLen = max(0LL, currLen - 1);
            }
            else if(s[i] == '#'){
                currLen *= 2;
            }
            else if(s[i] == '%'){
                currLen = currLen;
            }
            else{
                currLen++;
            }

            len[i] = currLen;
        }

        if(k >= currLen){
            return '.';
        }

        for(int i = n - 1; i >= 0; i--){

            if('a' <= s[i] && s[i] <= 'z'){

                long long oldLen = len[i] - 1;

                if(k == oldLen){
                    return s[i];
                }
            }
            else if(s[i] == '*'){
            }
            else if(s[i] == '#'){
                long long oldLen = len[i] / 2;
                if(oldLen > 0){
                    k %= oldLen;
                }
            }
            else{
                long long oldLen = len[i];
                k = oldLen - 1 - k;
            }
        }

        return '.';
    }
};
