class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        // code here.
        int n = arr.size();
        int ans = 0;
    
        int len = 1;
    
        for(int i = 1; i < n; i++){
            if(arr[i] > arr[i - 1]){
                len++;
            }
            else{
                ans += (len * (len - 1)) / 2;
                len = 1;
            }
        }
    
        // Last segment
        ans += (len * (len - 1)) / 2;
    
        return ans;
    }
};
