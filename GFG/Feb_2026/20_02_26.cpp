class Solution {
  public:
    static bool comp(string a, string b){
        return a + b > b + a;
    }

    string findLargest(vector<int> &arr) {
        int n = arr.size();
        
        vector<string> nums(n);
        for(int i = 0; i < n; i++){
            nums[i] = to_string(arr[i]);
        }
        
        sort(nums.begin(), nums.end(), comp);
        
        // If the largest number is "0", all are zeros
        if(nums[0] == "0")
            return "0";
        
        string result = "";
        for(int i = 0; i < n; i++){
            result += nums[i];
        }
        
        return result;
    }
};
