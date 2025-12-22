// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n = arr.size();
        int m = arr[0].size();
        
        int res = -1;
        int sum = 0;
        
        for(int i = 0; i < n; i++){
            int r_sum = 0;
            
            for(int j = 0; j < m; j++){
                r_sum += arr[i][j];
            }
            if(sum < r_sum){
                res = i;
                sum = r_sum;
            }
        }
        return res;
    }
};
