class Solution {
  public:
    bool canSeatAllPeople(int k, vector<int> &arr) {
        // code here
        int n = arr.size();
        
        if(arr[0] == 0 && arr[1] == 0){
            k--;
            arr[0] = 1;
        }
        
        if(arr[n-1] == 0 && arr[n-2] == 0){
            k--;
            arr[n-1] = 1;
        }
        
        for(int i = 2; i < n-1; i++){
            if(k <= 0)
                return true;
                
            if(arr[i] == 0 && arr[i-1] == 0 && arr[i+1] == 0){
                arr[i] = 1;
                k--;
            }
        }
        if(k <= 0)
            return true;
            
        return false;
    }
};
