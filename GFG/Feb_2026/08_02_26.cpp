class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        int maxEnding = arr[0];
        int minEnding = arr[0];
        int ans = arr[0];
        
        for(int i = 1; i < n; i++){
            if(arr[i] < 0){
                swap(maxEnding, minEnding);
            }
            
            maxEnding = max(arr[i], maxEnding * arr[i]);
            minEnding = min(arr[i], minEnding * arr[i]);
            
            ans = max(ans, maxEnding);
        }
        
        return ans;
    }
};
