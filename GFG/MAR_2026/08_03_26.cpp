class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        int n = arr.size();

        int mx = 0;
        for(int ele : arr){
            mx = max(mx, ele);
        }
    
        vector<bool> vis(mx + 1, false);
    
        for(int ele : arr){
            vis[ele] = true;
        }
    
        for(int a = 1; a <= mx; a++){
            if(!vis[a])
                continue;
    
            for(int b = 1; b <= mx; b++){
                if(!vis[b])
                    continue;
    
                int c = sqrt(a * a + b * b);
    
                if(c * c != a * a + b * b || c > mx)
                    continue;
    
                if(vis[c])
                    return true;
            }
        }
    
        return false;
    }
};
