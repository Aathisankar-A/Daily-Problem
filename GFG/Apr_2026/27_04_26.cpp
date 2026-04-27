class Solution {
  public:
    int smallestSubstring(string s) {
        // code here
        int n = s.size();
        int i = 0, j = 0;
        vector<int> freq(3, 0);
        int count = 0;
        int ans = INT_MAX;

        while(j < n){
            if(freq[s[j] - '0'] == 0) count++;
            freq[s[j] - '0']++;

            while(count == 3){
                ans = min(ans, j - i + 1);
                freq[s[i] - '0']--;
                if(freq[s[i] - '0'] == 0) count--;
                i++;
            }
            j++;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
