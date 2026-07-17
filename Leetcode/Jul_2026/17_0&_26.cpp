class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());

        vector<long long> f(mx + 1), ex(mx + 1), pre(mx + 1);

        for(int x : nums){
            f[x]++;
        }

        for(int i = mx; i >= 1; i--){
            long long cnt = 0;

            for(int j = i; j <= mx; j += i){
                cnt += f[j];
            }

            ex[i] = cnt * (cnt - 1) / 2;

            for(int j = i * 2; j <= mx; j += i){
                ex[i] -= ex[j];
            }
        }

        for(int i = 1; i <= mx; i++){
            pre[i] = pre[i - 1] + ex[i];
        }

        vector<int> ans;

        for(long long q : queries){
            ans.push_back(lower_bound(pre.begin() + 1, pre.end(), q + 1) - pre.begin());
        }

        return ans;
    }
};
