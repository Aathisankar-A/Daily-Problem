class Solution {
  public:
    int minTime(int n, int s1, int s2) {
        // code here
        long long low = 1;
        long long high = min(s1, s2) * n;
        long long ans = high;

        while(low <= high){
            long long mid = low + (high - low) / 2;

            if(mid / s1 + mid / s2 >= n){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};
