class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);

        for(auto i : invocations){
            graph[i[0]].push_back(i[1]);
        }

        queue<int> q;
        q.push(k);

        vector<int> vis(n, 0);

        while(!q.empty()){
            int top = q.front();
            q.pop();

            vis[top] = 1;

            for(int node : graph[top]){
                if(!vis[node]){
                    q.push(node);
                }
            }
        }

        vector<int> ans;

        int flag = 0;

        for(auto i : invocations){
            int u = i[0];
            int v = i[1];

            if(vis[u] == 0 && vis[v] == 1){
                flag = 1;
                break;
            }
        }

        if(flag == 1){
            for(int i = 0; i < n; i++){
                ans.push_back(i);
            }
        }
        else{
            for(int i = 0; i < n; i++){
                if(vis[i] == 0){
                    ans.push_back(i);
                }
            }
        }
        
        return ans;
    }
};
