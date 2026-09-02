class Solution {
  public:
    int solve(int n, string s) {
        // code here
        vector<int> vis(26,0);
        int free = n;
        int res = 0;

        for(char ch:s){
            int x = ch - 'A';

            if(vis[x] == 0){
                if(free > 0){
                    free --;
                    vis[x] = 1;
                }
                else{
                    res ++;
                    vis[x] = 2;
                }
            }
            else if(vis[x] == 1){
                free ++;
                vis[x] = 0;
            }
            else{
                vis[x] = 0;
            }
        }

        return res;
    }
};
