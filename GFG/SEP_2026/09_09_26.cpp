class Solution {
  public:
    int findMax(int n) {
        // code Here
        string s = to_string(n);
        int ans = n;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0'){
                continue;
            }

            string t = s;
            t[i]--;

            for(int j = i + 1; j < t.size(); j++){
                t[j] = '9';
            }

            int x = stoi(t);
            int sum1 = 0, sum2 = 0;

            for(char c : to_string(ans)){
                sum1 += c - '0';
            }

            for(char c : to_string(x)){
                sum2 += c - '0';
            }

            if(sum2 > sum1 || (sum2 == sum1 && x > ans)){
                ans = x;
            }
        }

        return ans;
    }
};
