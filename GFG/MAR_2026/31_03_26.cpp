class Solution {
  public:
    int maxProfit(vector<int>& arr, int k) {
        // Code here
        int n = arr.size();
        
        int hold = -arr[0];   // holding stock
        int cash = 0;         // not holding stock
        
        for(int i = 1; i < n; i++){
            int prevCash = cash;
            
            cash = max(cash, hold + arr[i] - k);   // sell
            hold = max(hold, prevCash - arr[i]);   // buy
        }
        
        return cash;
    }
};
