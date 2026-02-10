class Solution {
  public:
    int n;
    
    bool check(vector<int>& arr, int x, int k){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] % x == 0){
                cnt += arr[i] / x;
            }
            else{
                cnt += arr[i] / x + 1;
            }
        }
        return cnt <= k;
    }
    
    
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        n = arr.size();
        
        int low = 1;
        int high = *max_element(arr.begin(), arr.end());
        int mid;
        
        while(low < high){
            mid = (low + high) / 2;
            
            if(check(arr, mid, k)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return high;
    }
};
