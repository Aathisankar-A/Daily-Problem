class Solution {
  public:
    int largestSumCycle(vector<int>& edge) {
        // code here
        int n = edge.size();
        vector<bool> vis(n, false);
        int ans = -1;

        for(int i = 0; i < n; i++){
            if(vis[i]) continue;

            unordered_map<int, int> mp;
            int u = i;

            while(u != -1 && !vis[u]){
                vis[u] = true;
                mp[u] = mp.size();
                u = edge[u];
            }

            if(u != -1 && mp.count(u)){
                long long sum = 0;
                int start = mp[u];

                for(auto& [node, idx] : mp){
                    if(idx >= start){
                        sum += node;
                    }
                }

                ans = max(ans, (int)sum);
            }
        }

        return ans;

    }
};
