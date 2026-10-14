class Solution {
  public:
    string findRollOut(string& s, vector<int>& roll) {
        // code here
        int n = roll.size();
        int cnt = 0;

        sort(roll.begin(), roll.end());
        int i = 0;
        for (int j = 0; j < n; j++) {
            while (i < roll[j]) {
                s[i] = 'a' + (((s[i] - 'a') + n - j) % 26);
                i++;
            }
        }
        return s;
    }
};
