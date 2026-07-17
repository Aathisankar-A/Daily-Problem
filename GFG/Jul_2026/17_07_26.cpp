class Solution {
  public:
    int maxDiffSubArrays(vector<int>& arr) {
        // code here
        int n = arr.size();

        vector<int> lmx(n), lmn(n), rmx(n), rmn(n);

        int cur = arr[0];
        lmx[0] = arr[0];
        for(int i = 1; i < n; i++){
            cur = max(arr[i], cur + arr[i]);
            lmx[i] = max(lmx[i - 1], cur);
        }

        cur = arr[0];
        lmn[0] = arr[0];
        for(int i = 1; i < n; i++){
            cur = min(arr[i], cur + arr[i]);
            lmn[i] = min(lmn[i - 1], cur);
        }

        cur = arr[n - 1];
        rmx[n - 1] = arr[n - 1];
        for(int i = n - 2; i >= 0; i--){
            cur = max(arr[i], cur + arr[i]);
            rmx[i] = max(rmx[i + 1], cur);
        }

        cur = arr[n - 1];
        rmn[n - 1] = arr[n - 1];
        for(int i = n - 2; i >= 0; i--){
            cur = min(arr[i], cur + arr[i]);
            rmn[i] = min(rmn[i + 1], cur);
        }

        int ans = 0;

        for(int i = 0; i < n - 1; i++){
            ans = max(ans, abs(lmx[i] - rmn[i + 1]));
            ans = max(ans, abs(lmn[i] - rmx[i + 1]));
        }

        return ans;
    }
};
