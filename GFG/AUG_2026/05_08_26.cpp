class Solution {
  public:
    long long solve(vector<int>& arr, int x){
        if(x < 0) return 0;

        int n = arr.size();
        long long cnt = 0;

        int l = 0;
        long long sum = 0;

        for(int r = 0; r < n; r++){
            sum += arr[r];

            while(sum > x){
                sum -= arr[l];
                l++;
            }

            cnt += (r - l + 1);
        }

        return cnt;
    }
    
    int countSubarray(vector<int>& arr, int left, int right) {
        // code here
        return solve(arr, right) - solve(arr, left - 1);
    }
};
