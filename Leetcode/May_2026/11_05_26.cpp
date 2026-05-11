class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;

        for(int i = 0; i < n; i++){
            vector<int> temp;

            int num = nums[i];
            while(num){
                temp.push_back(num%10);
                num /= 10;
            }

            for(int t = temp.size()-1; t >= 0; t--){
                ans.push_back(temp[t]);
            }
        }

        return ans;
    }
};
