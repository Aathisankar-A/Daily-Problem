class Solution {
  public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        // code here
        int m = n * n;

        vector<int> jump(m + 1, -1);

        for(int i = 0; i < lad.size(); i += 2){
            jump[lad[i]] = lad[i + 1];
        }

        for(int i = 0; i < sn.size(); i += 2){
            jump[sn[i]] = sn[i + 1];
        }

        vector<int> dis(m + 1, -1);
        queue<int> q;

        q.push(1);
        dis[1] = 0;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            if(u == m){
                return dis[u];
            }

            for(int dice = 1; dice <= 6; ++dice){
                int v = u + dice;

                if(v > m){
                    break;
                }

                if(jump[v] != -1){
                    v = jump[v];
                }

                if(dis[v] == -1){
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }

        return -1;
    }
};
