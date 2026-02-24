class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        int n1 = a.size();
        int n2 = b.size();
        
        set<int> st;
        
        vector<int> res;
        
        
        for(int i = 0; i < n1; i++){
            st.insert(a[i]);
        }
        
        for(int i = 0; i < n2; i++){
            st.insert(b[i]);
        }
        
        for(auto it = st.begin(); it != st.end(); it++){
            res.push_back(*it);
        }
        
        return res;
    }
};
