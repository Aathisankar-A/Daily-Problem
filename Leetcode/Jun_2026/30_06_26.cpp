class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        vector<int> fq(3, 0);

        int i = 0;
        int ans = 0;

        for(int j = 0; j < n; j++){
            fq[s[j] - 'a']++;

            while(fq[0] && fq[1] && fq[2]){
                ans += n-j;
                fq[s[i] - 'a']--;
                i++;
            }
        }
        return ans;
    }
};
