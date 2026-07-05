class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int mod = 1e9 + 7;
        int n = board.size();

        vector<int> ns(n + 1, -1), nw(n + 1, 0);

        for(int i = n - 1; i >= 0; i--){
            vector<int> cs(n + 1, -1), cw(n + 1, 0);

            for(int j = n - 1; j >= 0; j--){
                if(board[i][j] == 'X'){
                    continue;
                }

                if(board[i][j] == 'S'){
                    cs[j] = 0;
                    cw[j] = 1;
                    continue;
                }

                int mx = max({ns[j], cs[j + 1], ns[j + 1]});

                if(mx == -1){
                    continue;
                }

                long long ways = 0;

                if(ns[j] == mx){
                    ways += nw[j];
                }

                if(cs[j + 1] == mx){
                    ways += cw[j + 1];
                }

                if(ns[j + 1] == mx){
                    ways += nw[j + 1];
                }

                int val = (board[i][j] == 'E') ? 0 : board[i][j] - '0';

                cs[j] = mx + val;
                cw[j] = ways % mod;
            }

            ns = move(cs);
            nw = move(cw);
        }

        if(ns[0] == -1){
            return {0, 0};
        }

        return {ns[0], nw[0]};
    }
};
