class Solution {
  public:
    vector<string> graycode(int n) {
        // code here
        vector<string> res;
        int total = 1 << n;  // 2^n
        
        for(int i = 0; i < total; i++){
            int num = i ^ (i >> 1);
            
            string s = "";
            for(int j = n - 1; j >= 0; j--){
                if(num & (1 << j))
                    s += '1';
                else
                    s += '0';
            }
            
            res.push_back(s);
        }
        
        return res;r
    }
};
