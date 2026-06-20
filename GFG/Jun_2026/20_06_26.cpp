class Solution {
  public:
    int power(int base, string &exp){
        if(exp == "0") return 1;

        vector<int> cycle[10] = {
            {0},
            {1},
            {2, 4, 8, 6},
            {3, 9, 7, 1},
            {4, 6},
            {5},
            {6},
            {7, 9, 3, 1},
            {8, 4, 2, 6},
            {9, 1}
        };

        vector<int>& v = cycle[base];
        int len = v.size();

        int rem = 0;
        for(char ch : exp){
            rem = (rem * 10 + (ch - '0')) % len;
        }

        if(rem == 0) rem = len;

        return v[rem - 1];
    }
    
    int getLastDigit(string& a, string& b) {
        // code here
        if(b == "0") return 1;

        int lastDigit = a.back() - '0';

        return power(lastDigit, b);
    }
};
