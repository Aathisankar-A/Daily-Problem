class Solution {
  public:
    int minDiff(int k, vector<int> &arr) {
        // code here
        int n = arr.size();
        multiset<int> st;

        for(int i = 0; i < n; i++)
            st.insert(arr[i]);

        for(int i = 0; i < k; i++)
            st.erase(st.find(arr[i]));

        int ans = *st.rbegin() - *st.begin();

        for(int i = k; i < n; i++){
            st.insert(arr[i - k]);
            st.erase(st.find(arr[i]));

            int diff = *st.rbegin() - *st.begin();
            ans = min(ans, diff);
        }

        return ans;
    }
};
