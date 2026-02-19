class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        // code here
        int n = arr.size();
        unordered_set<int> st;
        
        for(int i = 0; i < n; i++){
            st.insert(arr[i]);
        }
        
        vector<int> res;
        
        for(int num = low; num <= high; num++){
            if(st.find(num) == st.end()){
                res.push_back(num);
            }
        }
        
        return res;
    }
};
