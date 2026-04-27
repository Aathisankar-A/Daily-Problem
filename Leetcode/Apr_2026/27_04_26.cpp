class Solution {
public:
    vector<pair<char, char>> mp = {
        {' ', ' '},
        {'l', 'r'},
        {'u', 'd'},
        {'l', 'd'},
        {'r', 'd'},
        {'l', 'u'},
        {'u', 'r'}
    };

    bool is_valid(int i, int j, int m, int n){
        return i < m && i >= 0 && j < n && j >= 0;
    }

    int func(int i, int j, int m, int n, char end, vector<vector<int>> &grid){
        while(true){
            if(i == m-1 && j == n-1) return 1;

            if(end == 'l'){
                if(is_valid(i, j-1, m, n)){
                    if(mp[grid[i][j-1]].first == 'r' || mp[grid[i][j-1]].second == 'r'){
                        end = mp[grid[i][j-1]].first == 'r' ? mp[grid[i][j-1]].second : mp[grid[i][j-1]].first;
                        j--;
                    } else break;
                } else break;
            }
            else if(end == 'r'){
                if(is_valid(i, j+1, m, n)){
                    if(mp[grid[i][j+1]].first == 'l' || mp[grid[i][j+1]].second == 'l'){
                        end = mp[grid[i][j+1]].first == 'l' ? mp[grid[i][j+1]].second : mp[grid[i][j+1]].first;
                        j++;
                    } else break;
                } else break;
            }
            else if(end == 'u'){
                if(is_valid(i-1, j, m, n)){
                    if(mp[grid[i-1][j]].first == 'd' || mp[grid[i-1][j]].second == 'd'){
                        end = mp[grid[i-1][j]].first == 'd' ? mp[grid[i-1][j]].second : mp[grid[i-1][j]].first;
                        i--;
                    } else break;
                } else break;
            }
            else if(end == 'd'){
                if(is_valid(i+1, j, m, n)){
                    if(mp[grid[i+1][j]].first == 'u' || mp[grid[i+1][j]].second == 'u'){
                        end = mp[grid[i+1][j]].first == 'u' ? mp[grid[i+1][j]].second : mp[grid[i+1][j]].first;
                        i++;
                    } else break;
                } else break;
            }

            if(i == 0 && j == 0) return -1;
        }
        return 0;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m == 1 && n == 1) return true;

        int i = 0, j = 0;

        if(grid[i][j] == 5) return false;

        if(grid[i][j] == 4){
            char end = mp[grid[i][j]].first;
            int res = func(i, j, m, n, end, grid);
            if(res == 1) return true;
            if(res == -1) return false;
        }

        char end = mp[grid[i][j]].second;
        int res = func(i, j, m, n, end, grid);
        if(res == 1) return true;
        if(res == -1) return false;

        return false;
    }
};
