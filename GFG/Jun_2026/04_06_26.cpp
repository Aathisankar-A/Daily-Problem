class Solution {
  public:
    int maxSubstring(string &s) {
        // code here
        int curr = 0;
        int mx = -1;

        for(char ch : s){
            int val = (ch == '0') ? 1 : -1;

            curr = max(val, curr + val);
            mx = max(mx, curr);
        }

        return mx;
    }
};
