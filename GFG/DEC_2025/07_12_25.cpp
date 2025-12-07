class Solution {
  public:
    int distinctSubseq(string &str) {
        // code here
        int mod = 1000000007;
        int n = str.size();
    
        vector<int> last(26, 0);
    
        int res = 1;
    
        for(int i = 1; i <= n; i++){
            int cur = ( (long long)2 * res % mod - last[str[i - 1] - 'a'] + mod ) % mod;
    
            last[str[i - 1] - 'a'] = res;
            res = cur;
        }
    
        return res;
    }
};
