class Solution {
  public:
    vector<int> par,sz;

    int find(int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void unite(int a,int b){
        a = find(a);
        b = find(b);

        if(a == b) return;

        if(sz[a] < sz[b]) swap(a,b);

        par[b] = a;
        sz[a] += sz[b];
    }
    
    int minEdgesReq(int n, vector<vector<int>>& edges) {
        // code here
        int m = edges.size();

        if(m < n-1) return -1;

        par.resize(n);
        sz.assign(n,1);

        for(int i = 0; i < n; i++){
            par[i] = i;
        }

        for(auto &e : edges){
            unite(e[0],e[1]);
        }

        int comp = 0;

        for(int i = 0; i < n; i++){
            if(find(i) == i){
                comp++;
            }
        }

        return comp-1;
    }
};
