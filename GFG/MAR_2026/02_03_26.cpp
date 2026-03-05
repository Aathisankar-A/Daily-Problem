class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        int l = 0;
        int r = n - 1;

        int lm = 0;
        int rm = 0;
        int ans = 0;

        while(l <= r){
            if(arr[l] <= arr[r]){
                if(arr[l] >= lm){
                    lm = arr[l];
                }
                else{
                    ans += lm - arr[l];
                }
                l++;
            }
            else{
                if(arr[r] >= rm){
                    rm = arr[r];
                }
                else{
                    ans += rm - arr[r];
                }
                r--;
            }
        }

        return ans;
    }
};
