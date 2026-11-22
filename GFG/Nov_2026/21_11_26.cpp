class Solution {
  public:
    int smallestSubWithSum(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        int i = 0;
        int sum = 0;
        int ans = INT_MAX;

        for(int j = 0; j < n; j++){
            sum += arr[j];

            while(sum > x){
                ans = min(ans, j - i + 1);
                sum -= arr[i];
                i++;
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};
