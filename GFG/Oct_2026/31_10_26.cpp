class Solution {
  public:
    int maxPackages(vector<int>& arr, int totalTime) {
        // code here
        int n = arr.size();
        int sum = 0, ans = 0;

        for(int i = 0; i < totalTime && i < n; i++){
            sum += arr[i];
        }

        ans = sum;

        for(int i = totalTime; i < n; i++){
            sum += arr[i] - arr[i - totalTime];
            ans = max(ans, sum);
        }

        return ans;
    }
};
