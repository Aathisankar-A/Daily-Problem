class Solution {
  public:
    int countSubstring(string& s) {
        // Code Here
        int n = s.size();

        int off = n;
        vector<int> f(2 * n + 1, 0);

        f[off] = 1;

        int pre = 0;
        long long sm = 0;
        long long ans = 0;

        for(char c : s){
            if(c == '1'){
                sm += f[pre + off];
                pre++;
            }
            else{
                sm -= f[pre - 1 + off];
                pre--;
            }

            ans += sm;
            f[pre + off]++;
        }

        return ans;
    }
};
