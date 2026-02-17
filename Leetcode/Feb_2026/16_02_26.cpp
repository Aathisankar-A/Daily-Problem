class Solution {
public:
    int reverseBits(int n) {
        int res = 0;
        int bit;
        int temp;

        for(int i = 0; i < 32; i++){
            bit = n & 1;
            temp = bit << (31 - i);
            res |= temp;
            n >>= 1;
        }
        return res;
    }
};
