class Solution {
  public:
    int formPyramid(vector<int>& arr) {
        // code here
        int n = arr.size();
        int tot = accumulate(arr.begin(), arr.end(), 0);

        vector<int> l(n), r(n);

        l[0] = 1;
        for(int i = 1; i < n; i++){
            l[i] = min(arr[i], l[i - 1] + 1);
        }

        r[n - 1] = 1;
        for(int i = n - 2; i >= 0; i--){
            r[i] = min(arr[i], r[i + 1] + 1);
        }

        int mx = 0;

        for(int i = 0; i < n; i++){
            mx = max(mx, min(l[i], r[i]));
        }

        return tot - mx * mx;
    }
};
