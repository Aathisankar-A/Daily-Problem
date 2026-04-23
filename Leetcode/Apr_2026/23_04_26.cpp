class Solution {
public:
    void func(vector<long long> &ans, vector<int> &pos){
        int n = pos.size();
        long long total = 0, prefix = 0;

        for(auto &i : pos)
            total += i;

        for(int i = 0; i < n; i++){
            long long left = (1ll * pos[i] * i) - prefix;
            prefix += pos[i];
            long long right = (total - prefix) - (1ll * pos[i] * (n - 1 - i));
            ans[pos[i]] = left + right;
        }
    }
    
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }

        for(auto &it : mp){
            vector<int> &pos = it.second;
            if(pos.size() > 1){
                func(ans, pos);
            }
        }

        return ans;
    }
};
