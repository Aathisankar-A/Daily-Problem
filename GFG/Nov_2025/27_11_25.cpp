class Solution {
  public:
    int subsetXORSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        int bits = 0;
    
        for(int i : arr)
            bits |= i;
    
        int res = bits * pow(2, n-1);
    
        return res;
    }
};
