class Solution {
  public:
    string minWindow(string &s, string &p) {
        // code here
        int n = s.size();
        int m = p.size();
        
        vector<int> freqP(26, 0);
        vector<int> freqS(26, 0);
        
        for(char c : p)
            freqP[c - 'a']++;
        
        int left = 0;
        int count = 0;
        int minLen = INT_MAX;
        int start = -1;
        
        for(int right = 0; right < n; right++){
            
            freqS[s[right] - 'a']++;
            
            if(freqP[s[right] - 'a'] != 0 &&
               freqS[s[right] - 'a'] <= freqP[s[right] - 'a'])
                count++;
            
            if(count == m){
                
                while(freqP[s[left] - 'a'] == 0 ||
                      freqS[s[left] - 'a'] > freqP[s[left] - 'a']){
                    
                    if(freqS[s[left] - 'a'] > freqP[s[left] - 'a'])
                        freqS[s[left] - 'a']--;
                    
                    left++;
                }
                
                int len = right - left + 1;
                
                if(len < minLen){
                    minLen = len;
                    start = left;
                }
            }
        }
        
        if(start == -1)
            return "";
        
        return s.substr(start, minLen);
    }
};
