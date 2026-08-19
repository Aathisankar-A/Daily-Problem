class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rows;

        for(auto seat : reservedSeats){
            int row = seat[0];
            int col = seat[1];

            if(col >= 2 && col <= 9){
                rows[row] |= (1 << col);
            }
        }

        int ans = 2 * (n - rows.size());

        int left = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int mid = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int right = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        for(auto it : rows){
            int mask = it.second;

            bool l = (mask & left) == 0;
            bool m = (mask & mid) == 0;
            bool r = (mask & right) == 0;

            if(l && r){
                ans += 2;
            }
            else if(l || m || r){
                ans += 1;
            }
        }

        return ans;
    }
};
