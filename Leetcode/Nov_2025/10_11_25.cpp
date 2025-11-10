class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        vector<int> st;

        int res = 0;

        for(int i : nums){
            while(!st.empty() && st.back() > i)
                st.pop_back();
            
            if(i == 0)
                continue;
            if(st.empty() || st.back() < i){
                st.push_back(i);
                res++;
            }
        }
        return res;
    }
};
