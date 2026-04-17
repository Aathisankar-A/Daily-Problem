class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        unordered_map<int, vector<int>> positions;

        for (int i = 0; i < n; i++) {
            positions[nums[i]].push_back(i);
        }

        vector<int> ans(n, -1);

        for (auto& entry : positions) {
            vector<int>& pos = entry.second;
            int m = pos.size();

            if (m == 1) continue;

            for (int i = 0; i < m; i++) {
                int curr = pos[i];

                int prev = pos[(i - 1 + m) % m];
                int next = pos[(i + 1) % m];

                int distPrev = abs(curr - prev);
                distPrev = min(distPrev, n - distPrev);

                int distNext = abs(curr - next);
                distNext = min(distNext, n - distNext);

                ans[curr] = min(distPrev, distNext);
            }
        }

        vector<int> res;
        for (int idx : queries) {
            res.push_back(ans[idx]);
        }

        return res;
    }
};
