class Solution {
  public:
    int findMinDiff(vector<int>& arr, int m) {
        // code here
        int n = arr.size();

        if(m > n){
            return -1;
        }

        sort(arr.begin(), arr.end());

        int ans = INT_MAX;

        for(int i = 0; i + m - 1 < n; i++){
            int diff = arr[i + m - 1] - arr[i];
            ans = min(ans, diff);
        }

        return ans;
    }
};
