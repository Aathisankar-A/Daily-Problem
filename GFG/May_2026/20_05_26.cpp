class Solution {
  public:
    bool isProduct(vector<int>& arr, long long target) {
        // code here
        unordered_set<int> st;

        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == 0){
                if(target == 0)
                    return true;

                continue;
            }

            if(target % arr[i] == 0){
                int need = target / arr[i];

                if(st.find(need) != st.end())
                    return true;
            }

            st.insert(arr[i]);
        }

        return false;
    }
};
