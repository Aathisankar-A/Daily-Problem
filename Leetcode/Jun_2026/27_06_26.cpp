class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> mp;

        for(int x : nums){
            mp[x]++;
        }

        int ans = 1;

        if(mp.count(1)){
            int cnt = mp[1];

            if(cnt & 1){
                ans = max(ans, cnt);
            }
            else{
                ans = max(ans, cnt - 1);
            }
        }

        for(auto &[st, cnt] : mp){
            if(st == 1){
                continue;
            }

            long long cur = st;
            int len = 0;

            while(mp.count(cur)){
                if(mp[cur] >= 2){
                    len += 2;
                    cur *= cur;
                }
                else{
                    len++;
                    break;
                }
            }

            if(len % 2 == 0){
                len--;
            }

            ans = max(ans, len);
        }

        return ans;
    }
};
