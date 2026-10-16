class Solution {
  public:
    int countAlwaysFound(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> suf(n);
        suf[n - 1] = arr[n - 1];

        for(int i = n - 2; i >= 0; i--){
            suf[i] = min(arr[i], suf[i + 1]);
        }

        int mx = INT_MIN, ans = 0;

        for(int i = 0; i < n; i++){
            if(arr[i] > mx && (i == n - 1 || arr[i] < suf[i + 1])){
                ans++;
            }
            mx = max(mx, arr[i]);
        }

        return ans;
    }
};
