class Solution {
  public:
    vector<int> freqInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        unordered_map<int, vector<int>> mp;
        
        int n = arr.size();
        
        for(int i = 0; i < n; i++){
            mp[arr[i]].push_back(i);
        }
        
        vector<int> ans;
        
        for(auto &q : queries){
            int l = q[0];
            int r = q[1];
            int x = q[2];
            
            if(mp.find(x) == mp.end()){
                ans.push_back(0);
                continue;
            }
            
            vector<int> &pos = mp[x];
            
            int left = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int right = upper_bound(pos.begin(), pos.end(), r) - pos.begin();
            
            ans.push_back(right - left);
        }
        
        return ans;
    }
};
