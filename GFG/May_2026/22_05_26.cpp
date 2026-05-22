class Solution {
  public:
    int cntOnes(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        int cnt1 = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    cnt1++;
                }
            }
        }
        
        queue<vector<int>> q;
        
        for(int i = 0; i < m; i++){
            if(grid[0][i] == 1){
                q.push({0, i});
            }
            if(grid[n-1][i] == 1){
                q.push({n-1, i});
            }
        }
        
        for(int i = 0; i < n; i++){
            if(grid[i][0] == 1){
                q.push({i, 0});
            }
            if(grid[i][m-1] == 1){
                q.push({i, m-1});
            }
        }
        
        vector<vector<int>> dir = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        while(!q.empty()){
            vector<int> top = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++){
                vis[top[0]][top[1]] = 1;
                
                int nr = top[0] + dir[i][0];
                int nc = top[1] + dir[i][1];
                
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] != 1 && grid[nr][nc] == 1){
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
        
        int cnt2 = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j] == 1){
                    cnt2++;
                }
            }
        }
        return abs(cnt1 - cnt2);
    }
};
