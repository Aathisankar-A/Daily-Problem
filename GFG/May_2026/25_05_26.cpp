class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) {
        // code here
        int n = arr.size();
        bool flag;
        
        for(int i = 0; i < end-start+1; i++){
            flag = false;
            for(int j = 0; j < n; j++){
                if(arr[j] == start+i){
                    flag = true;
                }
            }
            if(!flag){
                return flag;
            }
        }
        return true;
    }
};
