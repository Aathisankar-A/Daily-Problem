class Solution {
public:
    int countOdds(int low, int high) {
        int n = high - low + 1;
        
        return (n / 2) + (high % 2 && low % 2);
    }
};
