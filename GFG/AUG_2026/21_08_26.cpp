class Solution {
  public:
    int transform(string &s1, string &s2) {
        // code here
        if(s1.size() != s2.size()){
            return -1;
        }

        vector<int> freq(256, 0);

        for(char c : s1){
            freq[c]++;
        }

        for(char c : s2){
            freq[c]--;

            if(freq[c] < 0){
                return -1;
            }
        }

        int i = s1.size() - 1;
        int j = s2.size() - 1;
        int ans = 0;

        while(i >= 0){
            if(s1[i] == s2[j]){
                j--;
            }
            else{
                ans++;
            }

            i--;
        }

        return ans;
    }
};
