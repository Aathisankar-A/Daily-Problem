class Solution {
  public:
    bool canServe(vector<int> &arr) {
        // code here
        int n =  arr.size();
        
        int cnt5 = 0;
        int cnt10 = 0;
        
        for(int i = 0; i < n; i++){
            if(arr[i] == 5){
                cnt5++;
            }
            else{
                if(arr[i] == 10){
                    cnt10++;
                    
                    if(cnt5 > 0){
                        cnt5--;
                    }
                    else{
                        return false;
                    }
                }
                
                if(arr[i] == 20){
                    if(cnt5 > 0 && cnt10 > 0){
                        cnt10--;
                        cnt5--;
                    }
                    else if(cnt5 >= 3){
                        cnt5 -= 3;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
