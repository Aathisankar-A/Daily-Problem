class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mod = 12345;

        int sz = n * m;
        vector<long long> arr(sz);

        int k = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                arr[k++] = grid[i][j] % mod;
            }
        }

        vector<long long> pre(sz, 1), suf(sz, 1);

        for(int i = 1; i < sz; i++){
            pre[i] = (pre[i-1] * arr[i-1]) % mod;
        }

        for(int i = sz-2; i >= 0; i--){
            suf[i] = (suf[i+1] * arr[i+1]) % mod;
        }

        vector<vector<int>> ans(n, vector<int>(m));

        k = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans[i][j] = (pre[k] * suf[k]) % mod;
                k++;
            }
        }
        return ans;
    }
};
