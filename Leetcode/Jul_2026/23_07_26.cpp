class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if(n == 1 || n == 2)
            return n;

        int cnt = 0;

        while(n){
            n = n / 2;
            cnt++;
        }
        return pow(2, cnt);
    }
};
