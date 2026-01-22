class Solution {
  public:
    int subarrayRanges(vector<int>& arr) {
        // code here
        int n = arr.size();
        int res = 0;

        vector<int> leftMin(n), rightMin(n), leftMax(n), rightMax(n);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            leftMin[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            rightMin[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] < arr[i]){
                st.pop();
            }
            leftMax[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }
            rightMax[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        for(int i = 0; i < n; i++){
            int minCount = (i - leftMin[i]) * (rightMin[i] - i);
            int maxCount = (i - leftMax[i]) * (rightMax[i] - i);
            res += (maxCount - minCount) * arr[i];
        }

        return res;
    }
};
