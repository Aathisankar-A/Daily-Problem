class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        unordered_map<int,int> mp;
        int l = 0, ans = 0;
        
        for(int r = 0; r < n; r++){
            mp[arr[r]]++;
            
            while(mp.size() > 2){
                mp[arr[l]]--;
                if(mp[arr[l]] == 0)
                    mp.erase(arr[l]);
                l++;
            }
            
            ans = max(ans, r - l + 1);
        }
        
        return ans;
    }
};
