class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        for(vector<int> query : queries){
            // query = {l, r, k, v }
            int i = query[0];
            
            while(i <= query[1]){
                nums[i] = (( 1LL * (nums[i] % 1000000007) * (query[3] % 1000000007) ) % 1000000007);
                i += query[2];
            }
        }

        int ans = nums[0];

        for(int i = 1; i < n; i++){
            ans ^= nums[i];
        }
        return ans;
    }
};
