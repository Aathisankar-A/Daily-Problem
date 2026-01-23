class Solution {
  public:
    int maxPeople(vector<int> &arr) {
        // code here
        int n;
        n = arr.size();

        vector<int> prev(n, -1), next(n, n);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] < arr[i]){
                st.pop();
            }

            if(!st.empty()){
                prev[i] = st.top();
            }

            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] < arr[i]){
                st.pop();
            }

            if(!st.empty()){
                next[i] = st.top();
            }

            st.push(i);
        }

        int res = 0;

        for(int i = 0; i < n; i++){
            int leftBound;
            int rightBound;

            if(prev[i] == -1){
                leftBound = 0;
            }
            else{
                leftBound = prev[i] + 1;
            }

            if(next[i] == n){
                rightBound = n - 1;
            }
            else{
                rightBound = next[i] - 1;
            }

            int count;
            count = rightBound - leftBound + 1;

            res = max(res, count);
        }

        return res;
    }
};
