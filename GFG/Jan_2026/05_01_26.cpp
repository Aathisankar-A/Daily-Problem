class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        int res = 0;
        
        int curr = 0;
        for(int i = 0; i < k; i++){
            curr += arr[i];
        }
        
        res = curr;
        
        for(int i = k; i < n; i++){
            curr += arr[i] - arr[i-k];
            res = max(res, curr);
        }
        
        return res;
    }
};
