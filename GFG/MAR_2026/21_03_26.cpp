class Solution {
  public:
    vector<int> countBSTs(vector<int>& arr) {
        // Code here
        int n = arr.size();
        
        vector<int> C(7, 0);
        C[0] = 1;
        for(int i = 1; i <= 6; i++){
            for(int j = 0; j < i; j++){
                C[i] += C[j] * C[i - j - 1];
            }
        }

        vector<int> ans;

        for(int i = 0; i < n; i++){
            int L = 0, R = 0;

            for(int j = 0; j < n; j++){
                if(arr[j] < arr[i]) L++;
                else if(arr[j] > arr[i]) R++;
            }

            ans.push_back(C[L] * C[R]);
        }

        return ans;
    }
};
