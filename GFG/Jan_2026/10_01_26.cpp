class Solution {
  public:
    //this is for finding "AtMostK distinct"
    int helper(string &s, int k) { 
        if(k < 0)
            return 0;

        vector<int> freq(26, 0);
        int left = 0;
        int right = 0;
        int distinct = 0;
        
        int res = 0;

        for(right = 0; right < s.size(); right++){
            if(freq[s[right] - 'a'] == 0)
                distinct++;

            freq[s[right] - 'a']++;

            while(distinct > k){
                freq[s[left] - 'a']--;
                if(freq[s[left] - 'a'] == 0)
                    distinct--;
                left++;
            }

            res += (right - left + 1);
        }
        return res;
    }

    int countSubstr(string& s, int k) {
        // code here
        return helper(s, k) - helper(s, k-1);
    }
};
