class Solution {
  public:
    int largestSubsquare(vector<vector<char>> &mat) {
        // code here
        int n = mat.size();

        vector<vector<int>> r(n, vector<int>(n, 0));
        vector<vector<int>> d(n, vector<int>(n, 0));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]=='X'){
                    r[i][j] = 1;
                    d[i][j] = 1;

                    if(j>0){
                        r[i][j] += r[i][j-1];
                    }

                    if(i>0){
                        d[i][j] += d[i-1][j];
                    }
                }
            }
        }

        int res = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int len = min(r[i][j], d[i][j]);

                while(len>res){
                    int x = i-len+1;
                    int y = j-len+1;

                    if(x>=0 && y>=0 && r[x][j]>=len && d[i][y]>=len){
                        res = len;
                        break;
                    }

                    len--;
                }
            }
        }

        return res;
    }
};
