class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        // Code here
        int n = s1.size();
        int m = s2.size();

        int minLen = INT_MAX;
        int startIdx = -1;

        for(int i = 0; i < n; i++){
            if(s1[i] != s2[0])
                continue;

            int p1 = i;
            int p2 = 0;

            while(p1 < n && p2 < m){
                if(s1[p1] == s2[p2])
                    p2++;
                p1++;
            }

            if(p2 < m)
                break;

            int end = p1 - 1;
            p2 = m - 1;
            p1 = end;

            while(p1 >= i){
                if(s1[p1] == s2[p2]){
                    p2--;
                    if(p2 < 0)
                        break;
                }
                p1--;
            }

            int currLen = end - p1 + 1;
            if(currLen < minLen){
                minLen = currLen;
                startIdx = p1;
            }
        }

        if(startIdx == -1)
            return "";

        return s1.substr(startIdx, minLen);
    }
};
