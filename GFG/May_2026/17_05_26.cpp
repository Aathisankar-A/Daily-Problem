class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        vector<int> st;
        
        for(int i = 0; i < arr.size(); i++){
            
            if(!st.empty() && ((st.back() >= 0 && arr[i] < 0) || (st.back() < 0 && arr[i] >= 0))){
                st.pop_back();
            }
            else{
                st.push_back(arr[i]);
            }
        }
        
        return st;
    }
};
