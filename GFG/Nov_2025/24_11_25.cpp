class Solution {
  public:
    struct DSU{
        vector<int> p, r;
        
        DSU(int n): p(n), r(n, 0){
            for(int i = 0; i < n; i++) p[i] = i;
        }
        
        int find(int x){
            return p[x] == x ? x : p[x] = find(p[x]);
        }
        
        bool unite(int a, int b){
            a = find(a);
            b = find(b);
            if(a == b) return false;
            
            if(r[a] < r[b]) swap(a, b);
            p[b] = a;
            if(r[a] == r[b]) r[a]++;
            return true;
        }
    };
    
    int Kruskal(int V, vector<array<int,3>> &ed, int skipU, int skipV){
        DSU d(V);
        int cost = 0;
        int used = 0;
        
        for(auto &e : ed){
            int u = e[0], v = e[1], w = e[2];
            
            if((u == skipU && v == skipV) || (u == skipV && v == skipU))
                continue;
            
            if(d.unite(u, v)){
                cost += w;
                used++;
            }
        }
        
        if(used != V - 1) return INT_MAX;
        return cost;
    }

    int secondMST(int V, vector<vector<int>> &edges){
        // code here
        vector<array<int,3>> ed;
        for(auto &x : edges){
            ed.push_back({x[0], x[1], x[2]});
        }
        
        sort(ed.begin(), ed.end(), [](auto &a, auto &b){
            return a[2] < b[2];
        });
        
        DSU d(V);
        int mstCost = 0;
        vector<array<int,3>> mstEdges;
        
        for(auto &e : ed){
            if(d.unite(e[0], e[1])){
                mstCost += e[2];
                mstEdges.push_back(e);
            }
        }
        
        int secondBest = INT_MAX;
        
        for(auto &e : mstEdges){
            int c = Kruskal(V, ed, e[0], e[1]);
            if(c > mstCost && c < secondBest){
                secondBest = c;
            }
        }
        
        return (secondBest == INT_MAX ? -1 : secondBest);
    }
};
