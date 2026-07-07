class Solution {
  public:
    int largestArea(int n, int m, vector<vector<int>> &arr) {
        // code here
        if(arr.size() == 0){
            return n * m;
        }
        
        vector<int> br;
        vector<int> bc;
        
        br.push_back(0);
        bc.push_back(0);
        
        for(auto &a : arr){
            br.push_back(a[0]);
            bc.push_back(a[1]);
        }
        
        br.push_back(n+1);
        bc.push_back(m+1);
        
        sort(br.begin(), br.end());
        sort(bc.begin(), bc.end());
        
        int mxR = INT_MIN;
        
        for(int i = 1; i < br.size(); i++){
            int gap = br[i] - br[i-1] - 1;
            mxR = max(mxR, gap);
        }
        
        int mxC = INT_MIN;
        
        for(int i = 1; i < bc.size(); i++){
            int gap = bc[i] - bc[i-1] - 1;
            mxC = max(mxC, gap);
        }
        
        return mxR * mxC;
    }
};
