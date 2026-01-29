class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        vector<int> cnt(26, 0);
        queue<char> q;
        string ans = "";

        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            cnt[ch - 'a']++;
            q.push(ch);

            while(!q.empty() && cnt[q.front() - 'a'] > 1){
                q.pop();
            }

            if(q.empty()){
                ans.push_back('#');
            }
            else{
                ans.push_back(q.front());
            }
        }

        return ans;
    }
};
