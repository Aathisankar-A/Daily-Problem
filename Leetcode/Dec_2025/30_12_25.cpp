class Solution {
public:
    unordered_map<string, vector<char>> mpp;

    bool dfs(string bot, int i, string tem){
        if(bot.size() == 1)
            return true;

        if(i == bot.size() - 1){
            string nxt;
            return dfs(tem, 0, nxt);
        }

        string key = bot.substr(i, 2);

        for(char ch : mpp[key]){
            tem.push_back(ch);
            if(dfs(bot, i + 1, tem))
                return true;
            tem.pop_back();
        }
        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for(string &s : allowed){
            mpp[s.substr(0, 2)].push_back(s[2]);
        }

        string temp;
        return dfs(bottom, 0, temp);
    }
};
