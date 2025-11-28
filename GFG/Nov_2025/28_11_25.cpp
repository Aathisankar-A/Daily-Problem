class Solution {
  public:
    vector<int> subsetXOR(int n) {
        // code here
        vector<int> res;
        int xr;

        if(n % 4 == 0) xr = n;
        else if(n % 4 == 1) xr = 1;
        else if(n % 4 == 2) xr = n + 1;
        else xr = 0;

        if(xr == n){
            for(int i = 1; i <= n; i++) res.push_back(i);
        }
        else{
            int x = xr ^ n;

            if(x >= 1 && x <= n){
                for(int i = 1; i <= n; i++)
                    if(i != x) res.push_back(i);
            }
            else{
                for(int i = 1; i <= n; i++)
                    res.push_back(i);
                    
                res.push_back(x);
            }
        }

        return res;
    }
};
