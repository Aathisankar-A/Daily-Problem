class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 2) q.push({i, j});
                else if(mat[i][j] == 1) fresh++;
            }
        }

        if(fresh == 0) return 0;

        int t = 0;
        int drow[4] = {-1, 1, 0, 0};
        int dcol[4] = {0, 0, -1, 1};

        while(!q.empty()){
            int sz = q.size();
            bool f = false;

            for(int i = 0; i < sz; i++){
                auto it = q.front();
                q.pop();

                int r = it.first;
                int c = it.second;

                for(int k = 0; k < 4; k++){
                    int nr = r + drow[k];
                    int nc = c + dcol[k];

                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] == 1){
                        mat[nr][nc] = 2;
                        q.push({nr, nc});
                        fresh--;
                        f = true;
                    }
                }
            }

            if(f) t++;
        }

        if(fresh > 0) return -1;
        return t;
    }
};
