class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        unordered_map<int, int> mp;
        
        for(int i = 0; i < n; i++){
            mp[arr[i]]++;
        }
        
        int cnt = 0;
        
        for(int i = 0; i < n; i++){
            if(mp.count(arr[i]-1) <= 0){
                cnt++;
            }
        }
        
        return cnt;
    }
};
