class Solution {
  public:
    vector<int> dir = {-1, 0, 1, 0, -1};

    void dfs(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &vis){
        int n = mat.size();
        int m = mat[0].size();

        vis[i][j] = 1;

        for(int k = 0; k < 4; k++){
            int nr = i + dir[k];
            int nc = j + dir[k + 1];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m &&
               !vis[nr][nc] && mat[nr][nc] >= mat[i][j]){
                dfs(nr, nc, mat, vis);
            }
        }
    }
    
    int countCoordinates(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> visP(n, vector<int>(m, 0));
        vector<vector<int>> visQ(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            if(!visP[i][0])
                dfs(i, 0, mat, visP);

            if(!visQ[i][m - 1])
                dfs(i, m - 1, mat, visQ);
        }

        for(int j = 0; j < m; j++){
            if(!visP[0][j])
                dfs(0, j, mat, visP);

            if(!visQ[n - 1][j])
                dfs(n - 1, j, mat, visQ);
        }

        int cnt = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(visP[i][j] && visQ[i][j])
                    cnt++;
            }
        }

        return cnt;
    }
};
