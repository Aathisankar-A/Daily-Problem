class Solution {
  public:
    int maxAmount(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        const int MOD = 1000000007;
        
        priority_queue<int> pq(arr.begin(), arr.end());
        
        int ans = 0;
        
        while(k > 0 && !pq.empty()){
            int x = pq.top();
            pq.pop();
            
            ans = (ans % MOD + x % MOD) % MOD;
            
            x--;
            
            if(x > 0)
                pq.push(x);
            
            k--;
        }
        return ans;
    }
};
