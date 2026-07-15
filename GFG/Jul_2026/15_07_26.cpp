class Solution {
  public:
    int bitonic(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        vector<int> v1(n);
        vector<int> v2(n);
        
        v1[0] = 1;
        v2[n-1] = 1;
        
        for(int i = 1; i < n; i++){
            if(arr[i] >= arr[i-1]){
                v1[i] = v1[i-1] + 1;
            }
            else{
                v1[i] = 1;
            }
        }
        
        for(int i = n-2; i >= 0; i--){
            if(arr[i] >= arr[i+1]){
                v2[i] = v2[i+1] + 1;
            }
            else{
                v2[i] = 1;
            }
        }
        
        int ans = v1[0] + v2[0] - 1;
        
        for(int i = 1; i < n; i++){
            int val = v1[i] + v2[i] - 1;
            if(ans < val){
                ans = val;
            }
        }
        return ans;
    }
};
