class Solution {
public:
    bool canAliceWin(int n) {
        int r = 10;
        bool a = true;
        while(n >= r){
            n -= r;
            r--;
            a = !a;
        }
        return !a;
    }
};
