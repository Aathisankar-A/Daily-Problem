class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for(auto& e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));
        vector<int> tin(n), tout(n), depth(n);
        vector<int> bit(n);
        int timer = 0;

        for(int i = 0; i < n; i++){
            bit[i] = 1 << (s[i] - 'a');
        }

        vector<int> order;
        vector<int> par(n, -1);
        vector<int> it(n, 0);
        stack<int> st;
        st.push(0);
        par[0] = 0;

        while(!st.empty()){
            int u = st.top();

            if(it[u] == 0){
                tin[u] = timer++;
                order.push_back(u);
                up[0][u] = par[u];

                for(int j = 1; j < LOG; j++){
                    up[j][u] = up[j - 1][up[j - 1][u]];
                }
            }

            if(it[u] < (int)adj[u].size()){
                int v = adj[u][it[u]++];
                if(v == par[u]) continue;

                par[v] = u;
                depth[v] = depth[u] + 1;
                st.push(v);
            }
            else{
                tout[u] = timer++;
                st.pop();
            }
        }

        vector<int> fenwick(2 * n + 2, 0);

        auto update = [&](int idx, int val){
            for(idx++; idx < (int)fenwick.size(); idx += idx & -idx){
                fenwick[idx] ^= val;
            }
        };

        auto query = [&](int idx){
            int res = 0;
            for(idx++; idx > 0; idx -= idx & -idx){
                res ^= fenwick[idx];
            }
            return res;
        };

        for(int u = 0; u < n; u++){
            update(tin[u], bit[u]);
            update(tout[u], bit[u]);
        }

        auto lca = [&](int u, int v){
            if(depth[u] < depth[v]) swap(u, v);

            int diff = depth[u] - depth[v];
            for(int j = 0; j < LOG; j++){
                if(diff & (1 << j)) u = up[j][u];
            }

            if(u == v) return u;

            for(int j = LOG - 1; j >= 0; j--){
                if(up[j][u] != up[j][v]){
                    u = up[j][u];
                    v = up[j][v];
                }
            }

            return up[0][u];
        };

        vector<bool> ans;

        for(string& q : queries){
            stringstream ss(q);
            string type;
            int u, v;
            ss >> type >> u;

            if(type == "update"){
                char c;
                ss >> c;

                int nw = 1 << (c - 'a');
                int change = bit[u] ^ nw;

                update(tin[u], change);
                update(tout[u], change);

                bit[u] = nw;
                s[u] = c;
            }
            else{
                ss >> v;

                int w = lca(u, v);
                int mask = query(tin[u]) ^ query(tin[v]) ^ bit[w];

                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};
