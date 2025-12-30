class Solution {
  public:
    bool helper(int n, vector<int>& rank, int time) {
        int donuts = 0;

        for(int r : rank){
            int k = 0;
            int t = r;

            while(t <= time){
                k++;
                t += (k + 1) * r;
            }

            donuts += k;
            if(donuts >= n)
                return true;
        }
        return false;
    }
  
    int minTime(vector<int>& ranks, int n) {
        // code here
        int mn = *min_element(ranks.begin(), ranks.end());

        int low = 0;
        int high = mn * n * (n + 1) / 2;
        int res = high;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(helper(n, ranks, mid)){
                res = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return res;
    }
};
