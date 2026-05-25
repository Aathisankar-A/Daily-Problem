class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        if(s.back() & 1) return false;

        s[0] = 'v';

        int reach = 0;
        int maxR = maxJump;

        for(int i = minJump; i < n; i++){
            if(i > maxR) return false;

            reach += (s[i - minJump] == 'v');

            if(i > maxJump){
                reach -= (s[i - maxJump - 1] == 'v');
            }

            if(reach && (~s[i] & 1)){
                s[i] = 'v';
                maxR = i + maxJump;
            }
        }

        return reach;
    }
};
