class Solution {
  public:
    int maxIndexDifference(string &s) {
        // code here
        int n = s.size();
        int mx = 0;
        int k = -1;
    
        for(int i = 0; i < n; i++){
            if(s[i] == 'a'){
                k = i;
                break;
            }
        }
    
        if(k == -1)
            return -1;
    
        int l = -1;
    
        for(int i = k + 1; i < n; i++){
            int a = s[i] - 'a';
    
            if(s[i] == 'a')
                continue;
    
            if(mx >= a - 1){
                l = i;
                mx = max(mx, a);
            }
        }
    
        if(l == -1)
            return 0;
    
        return l - k;
    }
};
