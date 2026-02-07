class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        int left = 0;
        int right = 0;
        int cnt = 0;
        
        int res = 0;
        
        while(right < n){
            if(arr[right] == 0){
                cnt++;
            }
            
            while(cnt > k){
                if(arr[left] == 0){
                    cnt--;
                }
                left++;
            }
            
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};
