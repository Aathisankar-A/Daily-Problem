class Solution {
  public:
    int getMinimumDays(string &s, vector<int> &p) {
        // code here
        int n = s.size();

        vector<int> pos(n);

        for(int i = 0; i < n; i++){
            pos[p[i]] = i + 1;
        }

        int ans = 0;

        for(int i = 0; i < n - 1; i++){
            if(s[i] == s[i + 1]){
                ans = max(ans, min(pos[i], pos[i + 1]));
            }
        }

        return ans;
    }
};
