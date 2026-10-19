class Solution {
  public:
    int goodIndices(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> vis(n, 0);
        int ans = 0;
    
        for(int i = 0; i < n; i++){
            if(vis[i] != 0)
                continue;
    
            vector<int> path;
            int cur = i;
    
            while(cur >= 0 && cur < n && vis[cur] == 0 && arr[cur] != 0){
                vis[cur] = 1;
                path.push_back(cur);
                cur += arr[cur];
            }
    
            bool good = (cur < 0 || cur >= n || (cur >= 0 && cur < n && vis[cur] == 2));
    
            for(int j : path){
                vis[j] = good ? 2 : 3;
            }
    
            if(good)
                ans += path.size();
        }
    
        return ans;
    }
};
