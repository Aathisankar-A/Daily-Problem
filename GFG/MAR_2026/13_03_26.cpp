class Solution {
  public:
  
    bool valid(string s){
        if(s.size() > 1 && s[0] == '0')
            return false;

        int num = stoi(s);

        if(num >= 0 && num <= 255)
            return true;

        return false;
    }

    void solve(int index, int parts, string curr, string &s, vector<string> &ans){
        if(parts == 4 && index == s.size()){
            curr.pop_back();
            ans.push_back(curr);
            return;
        }

        if(parts >= 4)
            return;

        for(int len = 1; len <= 3; len++){
            if(index + len > s.size())
                break;

            string part = s.substr(index, len);

            if(valid(part)){
                solve(index + len, parts + 1, curr + part + ".", s, ans);
            }
        }
    }
    
    vector<string> generateIp(string &s) {
        // code here
        vector<string> ans;

        solve(0, 0, "", s, ans);

        return ans;
    }
};
