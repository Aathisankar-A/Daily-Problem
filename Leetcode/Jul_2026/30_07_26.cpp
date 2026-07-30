class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();

        int part = n / 8;
        int rem = n % 8;

        return (4 * part * (part + 1) + rem * (part + 1));
    }
};
