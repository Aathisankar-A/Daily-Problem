class Solution {
  public:
    void mergeSort(vector<int>& arr, int l, int m, int r){
        vector<int> res;
        int i = l, j = m + 1;
        
        while(i <= m && j <= r){
            if(arr[i] <= arr[j]) res.push_back(arr[i++]);
            else res.push_back(arr[j++]);
        }
        
        while(i <= m) res.push_back(arr[i++]);
        while(j <= r) res.push_back(arr[j++]);
        
        for(int k = l; k <= r; k++){
            arr[k] = res[k - l];
        }
    }
    
    void mergeTwoParts(vector<int>& arr) {
        // code here
        int n = arr.size(), m = -1;

        for(int i = 0; i < n - 1; i++){
            if(arr[i] > arr[i + 1]){
                m = i;
                break;
            }
        }

        if(m == -1) return;

        mergeSort(arr, 0, m, n - 1);
    }
};
