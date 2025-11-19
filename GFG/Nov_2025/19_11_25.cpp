class Solution {
  public:
    int minCostPath(vector<vector<int>>& mat) {
        // code here
        int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        
        int n = mat.size();
        int m = mat[0].size();
    
        vector<vector<int>> cost(n, vector<int>(m, INT_MAX));
        cost[0][0] = 0;

        priority_queue<pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>, greater<>> pq;
        pq.push({0, {0,0}});
    
        while(!pq.empty()){
            auto [currCost, cell] = pq.top();
            pq.pop();
            int x = cell.first, y = cell.second;

            if(currCost != cost[x][y]) continue;
            
            if(x == n-1 && y == m-1) return currCost;
    
            for(auto d : dir){
                int nx = x + d[0], ny = y + d[1];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                    int newCost = max(currCost, abs(mat[nx][ny] - mat[x][y]));

                    if(newCost < cost[nx][ny]){
                        cost[nx][ny] = newCost;
                        pq.push({newCost, {nx, ny}});
                    }
                }
            }
        }
    
        return cost[n-1][m-1];
    }
};
