class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        int n = arr.size();
        
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        int prefix = 0;
        int mx = 0;
        
        for(int i = 0; i < n; i++){
            if(arr[i] > k)
                prefix++;
            else
                prefix--;
            
            if(prefix > 0)
                mx = i + 1;
            
            if(mp.find(prefix) == mp.end())
                mp[prefix] = i;
                
            if(mp.find(prefix-1) != mp.end()){
                mx = max(mx, i - mp[prefix-1]);
            }
        }
        
        return mx;
    }
};
