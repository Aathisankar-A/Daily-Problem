class Solution {
  public:
    int minCost(string &s, string &t, vector<vector<char>> &transform,
                vector<int> &cost) {
        // code here
        int n = s.size();
        if(n != t.size()) return -1;
        vector<vector<int>> dist(26, vector<int>(26, 1000000000));
        for(int i = 0; i < 26; i++) dist[i][i] = 0;
        for(int i = 0; i < transform.size(); i++){
            int u = transform[i][0] - 'a';
            int v = transform[i][1] - 'a';
            dist[u][v] = min(dist[u][v], cost[i]);
        }
        for(int k = 0; k < 26; k++){
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < 26; j++){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        long long ans = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == t[i]) continue;
            int u = s[i] - 'a';
            int v = t[i] - 'a';
            int res = 1000000000;
            for(int c = 0; c < 26; c++){
                if(dist[u][c] != 1000000000 && dist[v][c] != 1000000000){
                    res = min(res, dist[u][c] + dist[v][c]);
                }
            }
            if(res == 1000000000) return -1;
            ans += res;
        }
        return ans;
    }
};
