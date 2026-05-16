class Solution {
  public:
    int findSmallest(vector<int> &arr) {
        // code here.
        sort(arr.begin(), arr.end());
        
        long long ans = 1;
        
        for(int i = 0; i < arr.size(); i++){
            
            if(arr[i] > ans){
                break;
            }
            
            ans += arr[i];
        }
        
        return ans;
    }
};
