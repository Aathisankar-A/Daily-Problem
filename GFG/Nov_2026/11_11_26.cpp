class Solution {
  public:
    bool checkWithinK(vector<int>& arr, int k) {
        // code here
        unordered_map<int, int> mp;

        for(int i = 0; i < arr.size(); i++){
            if(mp.find(arr[i]) != mp.end() && i - mp[arr[i]] <= k){
                return true;
            }

            mp[arr[i]] = i;
        }

        return false;
    }
};
