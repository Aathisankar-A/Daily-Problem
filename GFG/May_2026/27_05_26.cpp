class Solution {
  public:
    bool wifiRange(string &s, int x) {
        // code here
        int n = s.size();

        vector<int>cover(n + 1, 0);

        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                int l = max(0, i - x);
                int r = min(n - 1, i + x);

                cover[l]++;
                cover[r + 1]--;
            }
        }

        int curr = 0;

        for(int i = 0; i < n; i++){
            curr += cover[i];

            if(curr <= 0){
                return false;
            }
        }

        return true;
    }
};
