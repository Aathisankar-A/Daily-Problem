class Solution {
  public:
    int helper(vector<vector<int>>& mat, int val) {
        int n = mat.size();
        int row = n - 1;
        int col = 0;
        int cnt = 0;

        while(row >= 0 && col < n){
            if(mat[row][col] <= val){
                cnt += row + 1;
                col++;
            }
            else{
                row--;
            }
        }
        return cnt;
    }
  
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        int n = mat.size();
        int low = mat[0][0];
        int high = mat[n - 1][n - 1];
        int res = low;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(helper(mat, mid) >= k){
                res = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return res;
    }
};
