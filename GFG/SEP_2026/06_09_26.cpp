class Solution {
  public:
    long long pairAndSum(vector<int> &arr) {
        // code here
        int n = arr.size();
        long long ans = 0;
    
        for(int b = 0; b < 31; b++){
            long long cnt = 0;
    
            for(int x : arr){
                if(x & (1 << b)){
                    cnt++;
                }
            }
    
            ans += (cnt * (cnt - 1) / 2) * (1LL << b);
        }
    
        return ans;
    }
};
