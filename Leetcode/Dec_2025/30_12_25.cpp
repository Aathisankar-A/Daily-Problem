class Solution {
public:
    bool flag = false;

    vector<int> magicSq(vector<vector<int>>& grid, int sr, int er, int sc, int ec){
        vector<int> arr;
        vector<int> freq(10, 0);

        for(int row = sr; row <= er; row++){
            for(int col = sc; col <= ec; col++){
                if(grid[row][col] > 9){
                    flag = true;
                    return {};
                }
                arr.push_back(grid[row][col]);

                freq[grid[row][col]] = freq[grid[row][col]] + 1;
            }
        }
        for(int i = 1; i < freq.size(); i++){
            if(freq[i] == 0 || freq[i] > 1){
                flag = true;
                return {};
            }
        }
        return arr;
    }
    
    bool check(vector<int>& arr){
        int row1 = arr[0] + arr[1] + arr[2];
        int row2 = arr[3] + arr[4] + arr[5];
        int row3 = arr[6] + arr[7] + arr[8];
        
        int col1 = arr[0] + arr[3] + arr[6];
        int col2 = arr[1] + arr[4] + arr[7];
        int col3 = arr[2] + arr[5] + arr[8];
        
        int dia1 = arr[0] + arr[4] + arr[8];
        int dia2 = arr[2] + arr[4] + arr[6];

        if(row1 == row2 && row2 == row3 && col1 == col2 && col2 == col3 && dia1 == dia2){
            return true;
        }
        return false;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int res = 0;

        for(int i = 0; i < n-2; i++){
            for(int j = 0; j < m-2; j++){
                vector<int> arr = magicSq(grid, i, i+2, j, j+2);
                if(flag == true){
                    flag = false;
                    continue;
                }
                if(check(arr)){
                    res++;
                }
            }
        }
        return res;
    }
};
