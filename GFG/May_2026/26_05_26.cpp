class Solution {
  public:
    int minToggle(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        int t = 0;
        int o = 0;
        
        for(int i = 0; i < n; i++){
            if(arr[i] == 1){
                o++;
            }
            else{
                t = min(t+1, o);
            }
        }
        return t;
    }
};
