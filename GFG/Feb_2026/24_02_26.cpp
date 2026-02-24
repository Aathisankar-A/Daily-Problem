class Solution {
  public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        // code here
        int n = a1.size();

        unordered_map<int,int> mp;

        int prefix_sum = 0;
        int mx = 0;

        for(int i = 0; i < n; i++){
            prefix_sum += (a1[i] - a2[i]);

            if(prefix_sum == 0){
                mx = i + 1;
            }

            if(mp.find(prefix_sum) != mp.end()){
                mx = max(mx, i - mp[prefix_sum]);
            }
            else{
                mp[prefix_sum] = i;
            }
        }

        return mx;
    }
};
