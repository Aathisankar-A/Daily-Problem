class Solution {
  public:
    int minMoves(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> pos(n + 1);

        for(int i = 0; i < n; i++){
            pos[arr[i]] = i;
        }

        int mx = 1, cur = 1;

        for(int i = 2; i <= n; i++){
            if(pos[i - 1] < pos[i]){
                cur++;
            }
            else{
                cur = 1;
            }

            mx = max(mx, cur);
        }

        return n - mx;
    }
};
