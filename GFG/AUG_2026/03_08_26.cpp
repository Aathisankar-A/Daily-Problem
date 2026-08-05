class Solution {
  public:
    int maxSumWithK(vector<int>& arr, int k) {
        // code here
        int n = arr.size();

        vector<long long> pre(n + 1, 0);

        for(int i = 0; i < n; i++){
            pre[i + 1] = pre[i] + arr[i];
        }

        long long ans = LLONG_MIN;
        long long mn = pre[0];

        for(int i = k - 1; i < n; i++){
            mn = min(mn, pre[i - k + 1]);
            ans = max(ans, pre[i + 1] - mn);
        }

        return (int)ans;
    }
};
