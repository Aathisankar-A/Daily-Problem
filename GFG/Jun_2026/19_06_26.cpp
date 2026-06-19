class Solution {
  public:
    vector<int> optimalArray(vector<int> &arr) {
        // code here
        int n = arr.size();

        vector<int> pref(n);
        pref[0] = arr[0];

        for(int i = 1; i < n; i++){
            pref[i] = pref[i - 1] + arr[i];
        }

        vector<int> ans(n);

        for(int i = 0; i < n; i++){
            int m = i / 2;

            int left_cost = 0;

            if(m > 0){
                left_cost = arr[m] * m - pref[m - 1];
            }

            int right_sum = pref[i] - pref[m];
            int right_cost = right_sum - arr[m] * (i - m);

            ans[i] = left_cost + right_cost;
        }

        return ans;
    }
};
