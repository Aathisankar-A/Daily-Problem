class Solution {
  public:
    static int countBits(int x){
        return __builtin_popcount(x);
    }

    vector<int> sortBySetBitCount(vector<int>& arr) {
        // code here
        stable_sort(arr.begin(), arr.end(), [](int a, int b){
            return __builtin_popcount(a) > __builtin_popcount(b);
        });

        return arr;
    }
};
