class Solution {
  public:
    bool isNegativeWeightCycle(int V, vector<vector<int>>& edges) {
        // code here
        vector<long long> dis(V, 0);

        for(int i = 0; i < V; i++){
            bool flag = false;

            for(auto &it : edges){
                int u = it[0];
                int v = it[1];
                int w = it[2];

                if(dis[u] + w < dis[v]){
                    dis[v] = dis[u] + w;
                    flag = true;

                    if(i == V - 1){
                        return true;
                    }
                }
            }

            if(!flag){
                break;
            }
        }

        return false;
    }
};
