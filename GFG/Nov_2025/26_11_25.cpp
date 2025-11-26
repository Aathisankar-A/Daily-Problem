class Solution {
  public:
    int andInRange(int l, int r) {
        // code here
        int cnt = 0;
        while(l != r && l > 0){
            cnt++;
            l = l >> 1;
            r = r >> 1;
        }
    
        return (l << cnt);
    }
};
