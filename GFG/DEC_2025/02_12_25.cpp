class Solution {
  public:
    int maxScore(string &s, vector<vector<char>> &jumps) {
        // code here
        int n = s.size();

        for(char ch = 'a'; ch <= 'z'; ch++){
            jumps.push_back({ch, ch});
        }
    
        vector<vector<int>> nxtInd(n, vector<int>(26, -1));
        vector<int> lastInd(26, -1);
    
        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j < 26; j++)
                nxtInd[i][j] = lastInd[j];
    
            lastInd[s[i] - 'a'] = i;
        }
    
        vector<vector<int>> child(26);
    
        for(int i = 0; i < (int)jumps.size(); i++){
            char u = jumps[i][0];
            char v = jumps[i][1];
            child[u - 'a'].push_back(v);
        }
    
        vector<int> preScore(n + 1, 0);
    
        for(int i = 0; i < n; i++)
            preScore[i + 1] = preScore[i] + s[i];
    
        vector<int> dp(n, 0);
    
        for(int ind = n - 2; ind >= 0; ind--){
            int score = 0;
    
            for(int k = 0; k < (int)child[s[ind] - 'a'].size(); k++){
                char it = child[s[ind] - 'a'][k];
                int jmpInd = nxtInd[ind][it - 'a'];
    
                if(jmpInd == -1)
                    continue;
    
                int temp;
                if(it == s[ind])
                    temp = preScore[jmpInd] - preScore[ind + 1] + dp[jmpInd];
                else
                    temp = preScore[jmpInd] - preScore[ind] + dp[jmpInd];
    
                if(temp > score)
                    score = temp;
            }
    
            dp[ind] = score;
        }
    
        return dp[0];
    }
};
