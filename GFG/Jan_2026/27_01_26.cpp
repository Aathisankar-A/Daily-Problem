class Solution {
  public:
    vector<vector<int>> dir = {{0,-1}, {-1,0}, {0,1}, {1,0}};
    int n, m;
    int wordLen;
    
    bool dfs(vector<vector<char>>& mat, string& word, string& curr, vector<vector<bool>>& vis, int row, int col){
        vis[row][col] = true;
        curr.push_back(mat[row][col]);
        
        if(curr.size() == wordLen){
            if(curr == word){
                return true;
            }
        }
        
        for(int i = 0; i < 4; i++){
            int nrow = row + dir[i][0];
            int ncol = col + dir[i][1];
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            !vis[nrow][ncol] && mat[nrow][ncol] == word[curr.size()]){
                if(dfs(mat, word, curr, vis, nrow, ncol))
                    return true;
            }
        }
        
        vis[row][col] = false;
        curr.pop_back();
        
        return false;
    }
    
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        // Code here
        n = mat.size();
        m = mat[0].size();
        
        wordLen = word.size();
        string curr = "";
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == word[0]){
                    if(dfs(mat, word, curr, vis, i, j))
                        return true;
                }
            }
        }
        return false;
    }
};
