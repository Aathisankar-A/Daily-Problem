class Solution {
  public:
    int minimumSum(string &s) {
        // code here
        int n = s.size();
        int m = (n + 1) / 2;

        int prev = -1;
        long long res = 0;

        for(int i = 0; i < m; i++){
            char left = s[i];
            char right = s[n - 1 - i];

            if(left != '?' && right != '?' && left != right)
                return -1;

            char ch = left != '?' ? left : right;

            if(ch != '?'){
                int curr = (int)ch;

                if(prev != -1)
                    res += abs(curr - prev);

                prev = curr;
            }
        }

        return 2 * res;
    }
};
