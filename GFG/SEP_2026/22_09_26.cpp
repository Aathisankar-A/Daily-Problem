class Solution {
    
  public:
    string findLongestWord(string &s, vector<string> &d) {
        // code here
        int n = s.size();

        vector<vector<int>>next(n + 1, vector<int>(26, -1));

        for(int i = n - 1; i >= 0; i--){
            next[i] = next[i + 1];
            next[i][s[i] - 'a'] = i;
        }

        string ans = "";

        for(string& word : d){
            int pos = 0;
            bool ok = true;

            for(char c : word){
                if(pos >= n || next[pos][c - 'a'] == -1){
                    ok = false;
                    break;
                }

                pos = next[pos][c - 'a'] + 1;
            }

            if(ok){
                if(word.size() > ans.size() ||
                   (word.size() == ans.size() && word < ans)){
                    ans = word;
                }
            }
        }

        return ans;
    }
};
