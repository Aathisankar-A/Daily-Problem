class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int i = digits.size() - 1;
        while(i >= 0){
            if(i == digits.size() - 1){
                digits[i] += 1;
            }

            if(digits[i] == 10){
                digits[i] = 0;
                if(i > 0){
                    digits[i-1] += 1;
                }
                else{
                    digits.push_back(0);
                    digits[i] = 1;
                }
            }
            i--;
        }
        return digits;
    }
};
