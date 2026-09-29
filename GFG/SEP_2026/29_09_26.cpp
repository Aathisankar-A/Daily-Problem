class Solution {
  public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        int sx = knightPos[0] - 1;
        int sy = knightPos[1] - 1;
        int tx = targetPos[0] - 1;
        int ty = targetPos[1] - 1;

        if(sx == tx && sy == ty){
            return 0;
        }

        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<pair<int, int>> q;

        int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
        int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

        q.push({sx, sy});
        vis[sx][sy] = 1;

        int steps = 0;

        while(!q.empty()){
            int sz = q.size();
            steps++;

            while(sz--){
                auto [x, y] = q.front();
                q.pop();

                for(int k = 0; k < 8; k++){
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if(nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny]){
                        if(nx == tx && ny == ty){
                            return steps;
                        }

                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return -1;
    }
};
