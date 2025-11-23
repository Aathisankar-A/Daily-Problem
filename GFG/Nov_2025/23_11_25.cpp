class Solution {
  public:
    void dfs(int i, vector<bool>& v, vector<vector<int>>& stones) {
        if(v[i])  return;
            
        v[i] = true;
    
        for(int j = 0; j < stones.size(); j++){
            if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                dfs(j, v, stones);
            }
        }
    }

    int maxRemove(vector<vector<int>>& stones) {
        // Code here
        int n = stones.size();
    
        vector<bool> vis(n, false);
        int comp = 0;
    
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, vis, stones);
                comp++;
            }
        }
        return n - comp;
    }
};
