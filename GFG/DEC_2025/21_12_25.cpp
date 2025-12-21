class Solution {
  public:
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        vector<int> res;

        for(int i = 0; i < queries.size(); i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int x = queries[i][2];

            auto it1 = lower_bound(arr.begin() + l, arr.begin() + r + 1, x);
            auto it2 = upper_bound(arr.begin() + l, arr.begin() + r + 1, x);

            res.push_back(it2 - it1);
        }

        return res;
    }
};
