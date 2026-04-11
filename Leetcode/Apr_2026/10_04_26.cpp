class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }

        int res = INT_MAX;

        for(int i = 0; i < mp.size(); i++){
            vector<int> arr = mp[i];

            if(arr.size() < 3)
                continue;

            for(int j = 0; j+2 < arr.size(); j++){
                int dis = abs(arr[j] - arr[j+1]) + abs(arr[j+1] - arr[j+2]) + 
                            abs(arr[j+2] - arr[j]);

                res = min(res, dis);
            }
        }
        if(res != INT_MAX)
            return res;

        return -1;
    }
};
