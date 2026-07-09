class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> ans;

        vector<int> comp(n, 0);
        int id = 0;

        for(int i = 1; i < n; i++){
            if(nums[i] - nums[i-1] > maxDiff){
                id++;
            }
            comp[i] = id;
        }

        for(int i = 0; i < queries.size(); i++){
            int u = queries[i][0];
            int v = queries[i][1];

            ans.push_back(comp[u]==comp[v]);
        }
        return ans;
    }
};
