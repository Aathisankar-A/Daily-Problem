class Solution {
  public:
    bool canFormPalindrome(string &s) {
        // code here
        unordered_map<char, int> freq;

        for(char c : s){
            freq[c]++;
        }
    
        int oddCount = 0;
    
        for(auto it : freq){
            if(it.second % 2 != 0){
                oddCount++;
            }
        }
    
        if(oddCount <= 1)
            return true;
        else
            return false;
    }
};
