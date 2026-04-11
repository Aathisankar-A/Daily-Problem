class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        // Code here
        int n = arr.size();
        if(n < 3) return {};
    
        vector<int> leftMin(n), rightMax(n);
    
        // Fill leftMin
        leftMin[0] = arr[0];
        for(int i = 1; i < n; i++){
            leftMin[i] = min(leftMin[i - 1], arr[i]);
        }
    
        // Fill rightMax
        rightMax[n - 1] = arr[n - 1];
        for(int i = n - 2; i >= 0; i--){
            rightMax[i] = max(rightMax[i + 1], arr[i]);
        }
    
        // Find valid subsequence
        for(int j = 1; j < n - 1; j++){
            if(leftMin[j] < arr[j] && arr[j] < rightMax[j]){
                return {leftMin[j], arr[j], rightMax[j]};
            }
        }
    
        return {};
    }
};
