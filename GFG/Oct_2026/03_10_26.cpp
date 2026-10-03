class Solution {
  public:
    vector<vector<int>> formCoils(int n) {
        // code here
        int x = 1;
        int t = 0, b = 4 * n - 1, l = 0, r = 4 * n - 1;
        int m = 4 * n;
        vector<vector<int>> a(m, vector<int>(m));
        vector<vector<int>> res;
        vector<int> v1, v2;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                a[i][j] = x++;
            }
        }

        while(l <= r && t <= b){
            while(t <= b){
                for(int i = t; i <= b; i++){
                    v1.push_back(a[i][l]);
                }

                for(int i = b; i >= t; i--){
                    v2.push_back(a[i][r]);
                }

                r--;
                l++;
                break;
            }

            while(l <= r){
                for(int i = l; i <= r; i++){
                    v1.push_back(a[b][i]);
                }

                for(int i = r; i >= l; i--){
                    v2.push_back(a[t][i]);
                }

                b--;
                t++;
                break;
            }

            while(t <= b){
                for(int i = b; i >= t; i--){
                    v1.push_back(a[i][r]);
                }

                for(int i = t; i <= b; i++){
                    v2.push_back(a[i][l]);
                }

                r--;
                l++;
                break;
            }

            while(l <= r){
                for(int i = r; i >= l; i--){
                    v1.push_back(a[t][i]);
                }

                for(int i = l; i <= r; i++){
                    v2.push_back(a[b][i]);
                }

                b--;
                t++;
                break;
            }
        }

        res.push_back(v1);
        res.push_back(v2);

        return res;
    }
};
