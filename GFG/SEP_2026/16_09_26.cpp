class Solution {
  public:
    int dominantPairs(vector<int> &arr) {
        // Code here
        int n = arr.size();
        int m = n / 2;
        vector<int>a(arr.begin(), arr.begin() + m);
        vector<int>b(arr.begin() + m, arr.end());

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        long long res = 0;
        int j = 0;

        for(int i = 0; i < m; i++){
            while(j < m && (long long)a[i] >= 5LL * b[j]){
                j++;
            }

            res += j;
        }

        return (int)res;
    }
};
