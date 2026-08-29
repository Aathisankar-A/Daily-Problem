class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int,int>> v(n);

        for(int i = 0; i < n; i++){
            v[i] = {nums[i], i};
        }

        sort(begin(v), end(v));

        int l = 0;
        vector<int> idx(n);
        idx[0] = v[0].second;

        for(int i = 1; i < n; i++){
            if(v[i].first - v[i-1].first > limit){
                sort(begin(idx) + l, begin(idx) + i);
                l = i;
            }

            idx[i] = v[i].second;
        }

        sort(begin(idx) + l, end(idx));

        vector<int> ans(n);

        for(int i = 0; i < n; i++){
            ans[idx[i]] = v[i].first;
        }

        return ans;
    }
};
