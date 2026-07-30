class Solution {
  public:
    int maxSubsetXOR(vector<int> &arr) {
        // code here
        int n = arr.size();
        int idx = 0;

        for(int b = 31; b >= 0; b--){
            int mx = -1;

            for(int i = idx; i < n; i++){
                if(arr[i] & (1 << b)){
                    mx = i;
                    break;
                }
            }

            if(mx == -1)
                continue;

            swap(arr[idx], arr[mx]);

            for(int i = 0; i < n; i++){
                if(i != idx && (arr[i] & (1 << b))){
                    arr[i] ^= arr[idx];
                }
            }

            idx++;
        }

        int ans = 0;

        for(int i = 0; i < idx; i++){
            ans = max(ans, ans ^ arr[i]);
        }

        return ans;
    }
};
