class Solution {
  public:
    vector<vector<int>> res;
    void helper(vector<int>& arr, vector<int>& curr, vector<bool>& used, int n){
        if(curr.size() == n){
            res.push_back(curr);
            return;
        }
        
        for(int i = 0; i < used.size(); i++){
            if(!used[i]){
                curr.push_back(arr[i]);
                used[i] = true;
                helper(arr, curr, used, n);
                
                curr.pop_back();
                used[i] = false;
            }
        }
    }
    
    vector<vector<int>> permuteDist(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        vector<int> curr;
        vector<bool> used(n, false);
        
        helper(arr, curr, used, n);
        return res;
    }
};
