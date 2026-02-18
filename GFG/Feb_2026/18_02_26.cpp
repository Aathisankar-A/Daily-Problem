class Solution {
  public:
    long long mergeArray(vector<int>& arr, int left, int mid, int right){
        int i = left;
        int j = mid + 1;
        int k = 0;
        
        vector<int> temp(right - left + 1);
        long long count = 0;
    
        while(i <= mid && j <= right){
            if(arr[i] <= arr[j]){
                temp[k++] = arr[i++];
            }
            else{
                temp[k++] = arr[j++];
                count += (mid - i + 1);
            }
        }
    
        while(i <= mid){
            temp[k++] = arr[i++];
        }
    
        while(j <= right){
            temp[k++] = arr[j++];
        }
    
        for(int p = 0; p < k; p++){
            arr[left + p] = temp[p];
        }
    
        return count;
    }
    
    long long mergeSort(vector<int>& arr, int left, int right){
        long long count = 0;
    
        if(left < right){
            int mid = left + (right - left) / 2;
    
            count += mergeSort(arr, left, mid);
            count += mergeSort(arr, mid + 1, right);
            count += mergeArray(arr, left, mid, right);
        }
    
        return count;
    }
    
    int inversionCount(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        return mergeSort(arr, 0, n - 1);
    }
};
