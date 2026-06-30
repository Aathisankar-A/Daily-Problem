class Solution {
  public:
    int minInsAndDel(vector<int> &a, vector<int> &b) {
        // code here
        unordered_map<int, int> mp;
        
        int n = a.size(), m = b.size();
        
        for(int i = 0; i < m; i++){
            mp[b[i]] = i;
        }
        
        vector<int> v;
        
        for(int x : a){
            if(mp.find(x) != mp.end()){
                v.push_back(mp[x]);
            }
        }
        
        vector<int> lis;
        
        for(int x : v){
            auto it = lower_bound(lis.begin(), lis.end(), x);
            
            if(it == lis.end()){
                lis.push_back(x);
            }
            else{
                *it = x;
            }
        }
        
        int l = lis.size();
        
        return (n - l) + (m - l);
    }
};
