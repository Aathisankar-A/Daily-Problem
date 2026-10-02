class Solution {
public:
    void backtrack(int n, vector<string>& res, int open, int close, string curr){
        if(open == close && open == n){
            res.push_back(curr);
            return;
        }
        if(open < n){
            backtrack(n, res, open + 1, close, curr + "(");
        }
        if(close < open){
            backtrack(n, res, open, close + 1, curr + ")");
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(n, res, 0, 0, "");
        return res;
    }
};
