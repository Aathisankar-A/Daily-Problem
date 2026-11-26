class Solution {
  public:
    vector<int> countVowels(string &s, vector<vector<int>> &queries) {
        // code here
        int n = s.size();
        vector<int> pre(n, 0), ans;

        for(int i = 0; i < n; i++){
            pre[i] = (i > 0 ? pre[i - 1] : 0);

            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
               s[i] == 'o' || s[i] == 'u')
                pre[i]++;
        }

        for(auto &q : queries){
            int l = q[0], r = q[1];

            if(l == 0)
                ans.push_back(pre[r]);
            else
                ans.push_back(pre[r] - pre[l - 1]);
        }

        return ans;
    }
};
