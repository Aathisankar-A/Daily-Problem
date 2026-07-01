class Solution {
  public:
    int maxSumSubarray(vector<int>& arr) {
        // code here
        int n = arr.size();

        int noSkip = arr[0];
        int oneSkip = 0;
        int ans = arr[0];

        for (int i = 1; i < n; i++) {

            oneSkip = max(noSkip, oneSkip + arr[i]);

            noSkip = max(arr[i], noSkip + arr[i]);

            ans = max(ans, max(noSkip, oneSkip));
        }

        return ans;
    }
};
