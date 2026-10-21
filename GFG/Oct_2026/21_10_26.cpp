class Solution {
  public:
    int minSubarraySum(vector<int> &arr) {
        // code here
        int cur = arr[0];
        int res = arr[0];

        for(int i = 1; i < arr.size(); i++){
            cur = min(arr[i], cur + arr[i]);
            res = min(res, cur);
        }

        return res;
    }
};
