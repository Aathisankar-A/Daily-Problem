class Solution {
  public:
    vector<bool> processQueries(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        int n = arr.size();

        vector<int> inc(n), dec(n);
    
        inc[n - 1] = n - 1;
        for(int i = n - 2; i >= 0; i--) {
            if(arr[i] <= arr[i + 1])
                inc[i] = inc[i + 1];
            else
                inc[i] = i;
        }
    
        dec[n - 1] = n - 1;
        for(int i = n - 2; i >= 0; i--) {
            if(arr[i] >= arr[i + 1])
                dec[i] = dec[i + 1];
            else
                dec[i] = i;
        }
    
        vector<bool> ans;
    
        for(auto &q : queries) {
            int l = q[0];
            int r = q[1];
    
            if(inc[l] >= r)
                ans.push_back(true);
            else
                ans.push_back(dec[inc[l]] >= r);
        }
    
        return ans;
    }
};
