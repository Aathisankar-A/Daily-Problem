class Solution {
  public:
    vector<int> lexicographicallyLargest(vector<int> &arr) {
        // code here
        int n = arr.size();

        for(int i = 0; i < n;){
            int j = i + 1;

            while(j < n && arr[j] % 2 == arr[i] % 2)
                j++;

            sort(arr.begin() + i, arr.begin() + j, greater<int>());
            i = j;
        }

        return arr;
    }
};
