class Solution {
  public:
    int maxOnes(vector<int>& arr) {
        // code here
        int n = arr.size();

        int totalOnes = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] == 1) totalOnes++;
        }
    
        int maxSum = 0, currSum = 0;
    
        for(int i = 0; i < n; i++){
            int val;
            if(arr[i] == 0) val = 1;
            else val = -1;
    
            currSum = max(val, currSum + val);
            maxSum = max(maxSum, currSum);
        }
    
        return totalOnes + maxSum;
    }
};
