class Solution {
  public:
    int findPos(vector<int>& v, int x){
        int l = 0;
        int r = v.size() - 1;
        
        int ans = v.size();
    
        while(l <= r){
            int mid = (l + r) / 2;
    
            if(v[mid] >= x){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
    
        return ans;
    }
    
    int minDeletions(vector<int>& arr) {
        // code here
        vector<int> v;

        for(int x:arr){
            int p = findPos(v, x);

            if(p == v.size()){
                v.push_back(x);
            }
            else{
                v[p] = x;
            }
        }

        return arr.size() - v.size();
    }
};
