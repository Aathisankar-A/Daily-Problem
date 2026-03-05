class Solution{
public:
    int minSwaps(vector<vector<int>>& g){
        int n = g.size();
        vector<int> z(n);

        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = n - 1; j >= 0 && g[i][j] == 0; j--){
                cnt++;
            }
            z[i] = cnt;
        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            int need = n - i - 1;
            int j = i;

            while(j < n && z[j] < need){
                j++;
            }

            if(j == n)
                return -1;

            while(j > i){
                swap(z[j], z[j - 1]);
                j--;
                ans++;
            }
        }

        return ans;
    }
};
