class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int l = 0, cnt = 0, mn = n + 1;
        string ans = "";

        for(int r = 0; r < n; r++){
            if(s[r] == '1'){
                cnt++;
            }

            while(cnt > k){
                if(s[l] == '1'){
                    cnt--;
                }
                l++;
            }

            if(cnt == k){
                while(l <= r && s[l] == '0'){
                    l++;
                }

                int len = r - l + 1;
                string cur = s.substr(l, len);

                if(len < mn || (len == mn && cur < ans)){
                    mn = len;
                    ans = cur;
                }
            }
        }

        return ans;
    }
};
