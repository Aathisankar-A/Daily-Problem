class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        int k = 0;
        for(int x : arr){
            if(x == 1) k++;
        }
        
        if(k == 0) return -1;
        
        int zeros = 0;
        for(int i = 0; i < k; i++){
            if(arr[i] == 0) zeros++;
        }
        
        int ans = zeros;
        
        for(int i = k; i < n; i++){
            if(arr[i-k] == 0) zeros--;
            if(arr[i] == 0) zeros++;
            
            ans = min(ans, zeros);
        }
        
        return ans;
    }
};
