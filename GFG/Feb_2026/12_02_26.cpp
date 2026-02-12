class Solution {
  public:
    bool possible(vector<int>& arr, int n, int k, int w, long long target){
        vector<long long> diff(n + 1, 0);

        long long water = 0;
        long long used = 0;

        for(int i = 0; i < n; i++){
            water += diff[i];

            long long curr = arr[i] + water;

            if(curr < target){
                long long need = target - curr;
                used += need;

                if(used > k)
                    return false;

                water += need;

                if(i + w < n){
                    diff[i + w] -= need;
                }
            }
        }

        return true;
    }
    
    int maxMinHeight(vector<int> &arr, int k, int w) {
        // code here
        int n = arr.size();

        long long low = *min_element(arr.begin(), arr.end());
        long long high = low + k;
        long long ans = low;

        while(low <= high){
            long long mid = low + (high - low) / 2;

            if(possible(arr, n, k, w, mid)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return (int)ans;
    }
};
