class Solution {
  public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        unordered_map<int, int> mp;

        mp[0] = -1;

        int sum = 0;
        int ans = 0;

        for(int i = 0; i < n; i++){
            sum += arr[i];

            int rem = sum % k;

            if(rem < 0){
                rem += k;
            }

            if(mp.find(rem) != mp.end()){
                ans = max(ans, i - mp[rem]);
            }
            else{
                mp[rem] = i;
            }
        }

        return ans;
    }
};
