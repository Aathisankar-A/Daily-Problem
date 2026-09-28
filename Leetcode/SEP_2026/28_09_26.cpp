class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();

        int cnt = 0;
        int maxi = 0;

        for(auto& ch : s){
            // if(ch != '(' && ch != ')')  continue;

            if(ch == '('){
                cnt++;
                maxi = max(cnt, maxi);
            }
            else if(ch == ')'){
                cnt--;
            }
        }
        return maxi;
    }
};
