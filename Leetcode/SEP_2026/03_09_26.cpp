class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = INT_MAX;
        bool odd = false;

        for(auto t : nums1){
            if(t % 2){
                odd = true;
                mn = min(mn,t);
            }
        }

        if(!odd)
            return true;

        for(int t : nums1){
            if(t % 2 == 0 && mn > t)
                return false;
        }

        return true;
    }
};
