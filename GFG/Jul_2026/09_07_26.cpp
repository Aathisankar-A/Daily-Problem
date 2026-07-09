class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        // code here
        vector<int> cnt(k, 0);

        int ans = 0;

        for(int x : arr){
            int r = x % k;
            ans += cnt[(k - r) % k];
            cnt[r]++;
        }

        return ans;
    }
};
