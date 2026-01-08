class Solution {
  public:
    int countSubarrays(vector<int>& arr, int k) {
        // code here
        unordered_map<int, int> mp;
        mp[0] = 1;
    
        int cnt = 0;
        int res = 0;
    
        for(int x : arr){
            if(x % 2 == 1)
                cnt++;
    
            if(mp.count(cnt - k))
                res += mp[cnt - k];
    
            mp[cnt]++;
        }
    
        return res;
    }
};
