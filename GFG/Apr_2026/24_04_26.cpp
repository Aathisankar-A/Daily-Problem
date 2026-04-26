class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        int maxHeight = 0;
        int count = 0;
        
        for(int i = 0; i < n; i++){
            if(arr[i] >= maxHeight){
                count++;
                maxHeight = arr[i];
            }
        }
        
        return count;
    }
};
