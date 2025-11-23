class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        vector<int> r1, r2;

        for(int x: nums){
            sum += x;
            if(x % 3 == 1) r1.push_back(x);
            else if(x % 3 == 2) r2.push_back(x);
        }

        sort(r1.begin(), r1.end());
        sort(r2.begin(), r2.end());

        if(sum % 3 == 0) return sum;

        int res = 0;

        if(sum % 3 == 1){
            int a = 1e9, b = 1e9;

            if(r1.size() >= 1) a = r1[0];
            if(r2.size() >= 2) b = r2[0] + r2[1];

            res = sum - min(a, b);
        }
        else{
            int a = 1e9, b = 1e9;

            if(r2.size() >= 1) a = r2[0];
            if(r1.size() >= 2) b = r1[0] + r1[1];

            res = sum - min(a, b);
        }

        return res < 0 ? 0 : res;
    }
};
