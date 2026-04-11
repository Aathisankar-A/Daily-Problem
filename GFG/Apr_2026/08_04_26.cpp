class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        int l = 0;
        int r = n-1;
        
        while(l <= r){
            if(arr[l] == 1 ){
                if(arr[r] == 0){
                    arr[l] = 0;
                    arr[r] = 1;
                }
                else{
                    while(arr[r] == 1){
                        r--;
                    }
                }
            }
            else
                l++;
        }
    }
};
