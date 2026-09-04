class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        // code here
        int n = arr.size();

        int val = 0;
        for(int i = 0; i < m; i++){
            val += arr[i];
        }

        int ans = val;

        for(int i = 1; i < n; i++){
            val -= arr[(i - 1) % n];
            val += arr[(i + m - 1) % n];

            ans = max(ans, val);
        }

        return ans;
    }
};
