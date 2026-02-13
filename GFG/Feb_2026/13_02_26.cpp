class Solution {
  public:
    long long digitSum(long long x){
        long long sum = 0;
        while(x){
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
    
    int getCount(int n, int d) {
        // code here
        long long low = 1;
        long long high = n;
        long long start = -1;
        
        while(low <= high){
            long long mid = low + (high - low) / 2;
            
            if(mid - digitSum(mid) >= d){
                start = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        if(start == -1)
            return 0;
        
        return n - start + 1;
    }
};
