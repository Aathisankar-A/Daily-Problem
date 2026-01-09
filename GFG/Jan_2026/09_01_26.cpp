class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int res = 0;
    
        int left = 0, right = 0;
    
        unordered_map<int, int> freq;
        while(right < n){
            freq[arr[right]] += 1;

            if(freq[arr[right]] == 1)
                k -= 1;

            while(k < 0){
                freq[arr[left]] -= 1;
                if (freq[arr[left]] == 0)
                    k += 1;
                left += 1;
            }

            res += (right - left + 1);
            right += 1;
        }
        return res;
    }
};
