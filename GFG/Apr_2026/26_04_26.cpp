class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        // code here
        int i = 0, j = 0, k = 0;
        vector<int> ans;

        while(i < a.size() && j < b.size() && k < c.size()){
            
            if(a[i] == b[j] && b[j] == c[k]){
                if(ans.empty() || ans.back() != a[i]){
                    ans.push_back(a[i]);
                }
                i++;
                j++;
                k++;
            }
            else{
                int mn = min({a[i], b[j], c[k]});
                
                if(a[i] == mn){
                    i++;
                }
                else if(b[j] == mn){
                    j++;
                }
                else{
                    k++;
                }
            }
        }

        return ans;
    }
};
