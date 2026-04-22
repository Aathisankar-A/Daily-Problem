class Solution {
  public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        int n = arr.size();
        
        vector<int> pre(n);
        pre[0] = arr[0];
        
        for(int i = 1; i < n; i++){
            pre[i] = pre[i - 1] + arr[i];
        }
        
        vector<int> ans;
        
        for(int i = 0; i < queries.size(); i++){
            int l = queries[i][0];
            int r = queries[i][1];
            
            int sum;
            
            if(l == 0){
                sum = pre[r];
            }
            else{
                sum = pre[r] - pre[l - 1];
            }
            
            int len = r - l + 1;
            ans.push_back(sum / len);
        }
        
        return ans;
    }
};
