class Solution {
public:
    int findPivot(vector<int>& arr) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
    
        while(low < high){
            int mid = low + (high - low) / 2;
    
            if(arr[mid] > arr[high])
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
    
    int helper(vector<int>& arr, int left, int right, int x) {
        int l = left;
        int r = right;
        int res = left - 1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] <= x) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res - left + 1;
    }

    int countLessEqual(vector<int>& arr, int x) {
        // code here
        int p = findPivot(arr);
        
        int c1 = helper(arr, 0, p-1, x);
        int c2 = helper(arr, p, arr.size()-1, x);
        
        return c1 + c2;
    }
};
