class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> pre(2 * n + 1, 0);

        pre[n] = 1;

        int cnt = n;
        long long ps = 0;
        long long ans = 0;

        for(int x : nums){
            if(x == target){
                ps += pre[cnt];

                cnt++;
                pre[cnt]++;
            }
            else{
                cnt--;

                ps -= pre[cnt];
                pre[cnt]++;
            }

            ans += ps;
        }

        return ans;
    }
};
