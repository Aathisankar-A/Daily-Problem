class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        // int n = nums.size();
        unordered_map<int, int> freq;
        
        vector<int> res;
        
        for(int num : arr){
            freq[num]++;
            if(freq[num] > 1)
                res.push_back(num);
        }
        return res;
    }
};
