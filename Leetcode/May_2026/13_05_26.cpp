class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> delta((limit << 1) + 2, 0);

        for(int i = 0; i < (n >> 1); i++){
            int mn = nums[i];
            int mx = nums[n - 1 - i];

            if(mn > mx){
                swap(mn, mx);
            }

            delta[2] += 2;
            delta[mn + 1]--;
            delta[mn + mx]--;
            delta[mn + mx + 1]++;
            delta[mx + limit + 1]++;
        }

        int res = n;
        int moves = 0;

        for(int targ = 2; targ <= limit * 2; targ++){
            moves += delta[targ];

            res = min(res, moves);
        }

        return res;
    }
};
