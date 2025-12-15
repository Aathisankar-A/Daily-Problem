class Solution {
  public:
    int cntWays(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        int rEven = 0;
        int rOdd = 0;
        
        for(int i = 0; i < n; i++){
            if(i % 2 == 0)
                rEven += arr[i];
            else
                rOdd += arr[i];
        }
        
        int lOdd = 0;
        int lEven = 0;
        
        int res = 0;
        
        for(int i = 0; i < n; i++){
            if(i % 2 == 0)
                rEven -= arr[i];
            else
                rOdd -= arr[i];
                
            if(lOdd + rEven == lEven + rOdd)
                res++;
            
            if(i % 2 == 0)
                lEven += arr[i];
            else
                lOdd += arr[i];
        }
        return res;
    }
};
