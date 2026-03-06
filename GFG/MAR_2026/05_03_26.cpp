class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n = s.size();
        int i = 0;
        int j = 0;
        
        int cnt = 0;
        int mx = -1;
        
        vector<int> freq(26, 0);
        
        while(j < n){
            freq[s[j] - 'a']++;
            
            if(freq[s[j] - 'a'] == 1)
                cnt++;
            
            while(cnt > k){
                freq[s[i] - 'a']--;
                
                if(freq[s[i] - 'a'] == 0)
                    cnt--;
                    
                i++;
            }
            
            if(cnt == k)
                mx = max(mx, j - i + 1);
                
            j++;
        }
        return mx;
    }
};
