class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();

        int mx = 0;
        int pre = 0;

        for(int i = 0; i < n; i++){
            pre = pre + gain[i];
            mx = max(mx, pre);
        }
        return mx;
    }
};
