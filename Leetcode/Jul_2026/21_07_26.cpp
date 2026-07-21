class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();

        int cnt = 0;
        int ans = 0;
        int z = 0;

        int i = 0;

        while(i < n){
            z = 0;
            while(i < n && s[i] == '0'){
                z++;
                i++;
            }

            if(z != 0){
                if(cnt != 0)
                    ans = max(ans, cnt+z);
                cnt = z;
            }

            i++;
        }
        
        for(char i : s){
            if(i == '1'){
                ans++;
            }
        }
        return ans;
    }
};
