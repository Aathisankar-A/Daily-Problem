class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    // bool dfs(int x, int y, int px, int py, vector<vector<char>>& grid, vector<vector<bool>>& vis){
    //     vis[x][y] = true;

    //     int n = grid.size();
    //     int m = grid[0].size();

    //     for(int d = 0; d < 4; d++){
    //         int nx = x + dx[d];
    //         int ny = y + dy[d];

    //         if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
    //         if(grid[nx][ny] != grid[x][y]) continue;

    //         if(vis[nx][ny] && !(nx == px && ny == py)) return true;

    //         if(!vis[nx][ny]){
    //             if(dfs(nx, ny, x, y, grid, vis)) return true;
    //         }
    //     }
    //     return false;
    // }

    bool containsCycle(vector<vector<char>>& grid) {
        // int n = grid.size();
        // int m = grid[0].size();

        // vector<vector<bool>> vis(n, vector<bool>(m, false));

        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         if(!vis[i][j]){
        //             if(dfs(i, j, -1, -1, grid, vis)) return true;
        //         }
        //     }
        // }
        // return false;

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(vis[i][j]) continue;

                queue<vector<int>> q;
                q.push({i, j, -1, -1});
                vis[i][j] = true;

                while(!q.empty()){
                    auto v = q.front();
                    q.pop();

                    int x = v[0];
                    int y = v[1];
                    int px = v[2];
                    int py = v[3];

                    for(int d=0; d<4; d++){
                        int nx = x + dx[d];
                        int ny = y + dy[d];

                        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        if(grid[nx][ny] != grid[x][y]) continue;

                        if(vis[nx][ny] && !(nx == px && ny == py)) return true;
                        if(vis[nx][ny]) continue;

                        q.push({nx, ny, x, y});
                        vis[nx][ny] = true;
                    }
                }
            }
        }
        return false;
    }
};
