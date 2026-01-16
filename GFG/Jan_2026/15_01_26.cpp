class Solution {
  public:
    int minCandy(vector<int> &arr) {
        // code here
        int n = arr.size();
        if(n == 0) return 0;

        vector<int> candy(n, 1);

        for(int i = 1; i < n; i++){
            if(arr[i] > arr[i - 1]){
                candy[i] = candy[i - 1] + 1;
            }
        }

        for(int i = n - 2; i >= 0; i--){
            if(arr[i] > arr[i + 1]){
                candy[i] = max(candy[i], candy[i + 1] + 1);
            }
        }

        int res = 0;
        for(int i = 0; i < n; i++){
            res += candy[i];
        }

        return res;
    }
};
