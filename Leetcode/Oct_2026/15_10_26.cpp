class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;

        for(int i = 0; i < n; i++){
            unordered_map<int, int> mp;
            int cnt = 0;

            for(int j = i; j < n; j++){
                if(mp[nums[j]] == 0){
                    cnt++;
                }

                mp[nums[j]]++;
                res += 1LL * cnt * cnt;
            }
        }

        return res;
    }
};
