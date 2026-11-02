class Solution {
  public:
    int maximumSubarray(vector<int>& arr) {
        // code here
        int n = arr.size();

        int dp0 = arr[0];
        int dp1 = arr[0] * arr[0];
        int ans = dp1;

        for(int i = 1; i < n; i++){
            int x = arr[i];

            dp1 = max({x * x, dp0 + x * x, dp1 + x});
            dp0 = max(x, dp0 + x);

            ans = max(ans, dp1);
        }

        return ans;
    }
};
