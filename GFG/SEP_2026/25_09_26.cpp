class Solution {
  public:
    vector<vector<int>> box;
    vector<int> dp;

    int dfs(int i){
        if(dp[i] != -1){
            return dp[i];
        }

        int res = 0;

        for(int j = 0; j < box.size(); j++){
            if(box[j][0] < box[i][0] && box[j][1] < box[i][1]){
                res = max(res, dfs(j));
            }
        }

        return dp[i] = box[i][2] + res;
    }
    
    int maxHeight(vector<int> &height, vector<int> &width, vector<int> &length) {
        // code here
        int n = height.size();

        for(int i = 0; i < n; i++){
            int a = height[i], b = width[i], c = length[i];

            box.push_back({max(b, c), min(b, c), a});
            box.push_back({max(a, c), min(a, c), b});
            box.push_back({max(a, b), min(a, b), c});
        }

        dp.assign(3 * n, -1);

        int ans = 0;

        for(int i = 0; i < 3 * n; i++){
            ans = max(ans, dfs(i));
        }

        return ans;
    }
};
