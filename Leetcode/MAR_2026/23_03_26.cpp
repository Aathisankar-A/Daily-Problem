class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        long long mod = 1e9 + 7;
        
        vector<vector<long long>> mx(n, vector<long long>(m, 0));
        vector<vector<long long>> mn(n, vector<long long>(m, 0));
        
        mx[0][0] = mn[0][0] = grid[0][0];
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                if(i == 0 && j == 0) continue;
                
                long long a = LLONG_MIN;
                long long b = LLONG_MAX;
                
                if(i > 0){
                    long long x1 = mx[i-1][j] * grid[i][j];
                    long long x2 = mn[i-1][j] * grid[i][j];
                    
                    a = max(a, max(x1, x2));
                    b = min(b, min(x1, x2));
                }
                
                if(j > 0){
                    long long x1 = mx[i][j-1] * grid[i][j];
                    long long x2 = mn[i][j-1] * grid[i][j];
                    
                    a = max(a, max(x1, x2));
                    b = min(b, min(x1, x2));
                }
                
                mx[i][j] = a;
                mn[i][j] = b;
            }
        }
        
        long long ans = mx[n-1][m-1];
        
        if(ans < 0) return -1;
        
        return ans % mod; 
    }
};
