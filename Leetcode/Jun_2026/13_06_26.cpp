class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();

        string res = "";

        for(string &word : words){
            int sum = 0;
            for(char &ch : word){
                sum += weights[ch%97];
            }
            sum %= 26;

            res += char(122 - sum);
        }
        return res;
    }
};
