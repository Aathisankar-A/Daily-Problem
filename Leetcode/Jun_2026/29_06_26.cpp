class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = patterns.size();
        int m = word.size();

        int ans = 0;

        for(string p : patterns){
            if(word.contains(p)){
                ans++;
            }
        }
        return ans;
    }
};
