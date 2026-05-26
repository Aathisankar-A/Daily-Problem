class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();

        unordered_map<char, int> mp;

        for(int i = 0; i < n; i++){
            mp[word[i]]++;
        }

        int cnt = 0;

        for(char ch = 'A'; ch <= 'Z'; ch++){
            if(mp[ch] > 0){
                if(mp[ch+32] > 0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
