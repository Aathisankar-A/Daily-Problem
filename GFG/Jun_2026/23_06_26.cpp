class Solution {
  public:
    int maxPeopleDefeated(int p) {
        // Code Here
        int low = 0;
        int high = 1000;
        
        int ans = 0;
        long long sum = 0;

        while(low <= high){
            int mid = low + (high - low) / 2;

            sum = 1LL * mid * (mid + 1) * (2 * mid + 1) / 6;

            if(sum <= p){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }
};
