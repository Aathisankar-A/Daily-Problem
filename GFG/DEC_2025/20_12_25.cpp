class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        // code here
        int left = 0;
        int right = arr.size()-1;
        int mid;
        
        while(left <= right){
            mid = (left + right) / 2;
            
            if(arr[mid] == k)
                return mid;
            
            if(arr[mid] < k)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
};
