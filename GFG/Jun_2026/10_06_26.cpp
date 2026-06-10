class Solution {
  public:
    bool check(int key, vector<int>& arr, int n){
        int l = 0;
        int r = n - 1;

        while(l <= r){
            int mid = (l + r) / 2;

            if(arr[mid] == key){
                return true;
            }

            if(arr[mid] < key){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }

        return false;
    }
    
    int binarySearchable(vector<int>& arr) {
        // code here
        int n = arr.size();

        int cnt = 0;

        for(int x : arr){
            if(check(x, arr, n)){
                cnt++;
            }
        }

        return cnt;
    }
};
