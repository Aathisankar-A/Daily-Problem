class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int> freq;
        int xr = 0;
        int count = 0;

        freq[0] = 1;

        for(int i = 0; i < arr.size(); i++){
            xr ^= arr[i];

            if(freq.find(xr ^ k) != freq.end())
                count += freq[xr ^ k];

            freq[xr]++;
        }

        return count;
    }
};
