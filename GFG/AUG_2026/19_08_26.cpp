class Solution {
  public:
  int count(vector<int>& arr, int x) {
      int n = arr.size();
      int ans = 0;
    
      for(int i = 0; i < n - 2; i++){
          int j = i + 1;
          int k = n - 1;
    
          while(j < k){
              int sum = arr[i] + arr[j] + arr[k];
    
              if(sum <= x){
                  ans += k - j;
                  j++;
              }
              else{
                  k--;
              }
          }
      }
    
      return ans;
  }
  
  int countTriplets(vector<int> &arr, int l, int r) {
        // code here
        sort(arr.begin(), arr.end());

        return count(arr, r) - count(arr, l - 1);
    }
};
