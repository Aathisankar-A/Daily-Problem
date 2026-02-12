class Solution {
  public:
    long long getcost(vector<int>& h, vector<int>& c, int target){
        long long total = 0;
        int n = h.size();

        for(int i = 0; i < n; i++){
            total += 1LL * abs(h[i] - target) * c[i];
        }

        return total;
    }
    
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
        int n = heights.size();

        int low = *min_element(heights.begin(), heights.end());
        int high = *max_element(heights.begin(), heights.end());

        long long ans = LLONG_MAX;

        while(low <= high){
            int mid = (low + high) / 2;

            long long cost1 = getcost(heights, cost, mid);
            long long cost2 = getcost(heights, cost, mid + 1);

            ans = min(cost1, cost2);

            if(cost1 < cost2){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return (int)ans;
    }
};
