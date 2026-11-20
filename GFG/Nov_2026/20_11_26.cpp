class Solution {
  public:
    int minFlips(string &s) {
        // code here
        int n = s.size();
        
        int cnt1 = 0;
        int cnt2 = 0;
        
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            if( (i%2 == 0 && s[i] == '1') || (i%2 == 1 && s[i] == '0') ){
                cnt1++;
            }
        }
        
        for(int i = 0; i < n; i++){
            if((i%2 == 0 && s[i] == '0') || (i%2 == 1 && s[i] == '1')){
                cnt2++;
            }
        }
        
        return min(cnt1, cnt2);
    }
};
