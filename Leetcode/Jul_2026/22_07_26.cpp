class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();

        int one = 0;
        for(char c:s){
            if(c == '1'){
                one++;
            }
        }

        vector<int> t, st, en;

        for(int i = 0;i < n;){
            int j = i;
            while(j < n && s[j] == s[i]){
                j++;
            }
            t.push_back(s[i] - '0');
            st.push_back(i);
            en.push_back(j - 1);
            i = j;
        }

        int m = t.size();

        vector<int> seg(n);
        for(int i = 0;i < m;i++){
            for(int j = st[i];j <= en[i];j++){
                seg[j] = i;
            }
        }

        vector<int> mx(m, 0);
        for(int i = 1;i < m - 1;i++){
            if(t[i] == 1){
                mx[i] = (en[i - 1] - st[i - 1] + 1) + (en[i + 1] - st[i + 1] + 1);
            }
        }

        vector<int> lg(m + 1, 0);
        for(int i = 2;i <= m;i++){
            lg[i] = lg[i / 2] + 1;
        }

        int k = lg[m] + 1;
        vector<vector<int>> sp(k, vector<int>(m));

        for(int i = 0;i < m;i++){
            sp[0][i] = mx[i];
        }

        for(int j = 1;j < k;j++){
            for(int i = 0;i + (1 << j) <= m;i++){
                sp[j][i] = max(sp[j - 1][i], sp[j - 1][i + (1 << (j - 1))]);
            }
        }

        auto rmq = [&](int l, int r){
            if(l > r){
                return 0;
            }
            int j = lg[r - l + 1];
            return max(sp[j][l], sp[j][r - (1 << j) + 1]);
        };

        auto calc = [&](int i, int l, int r, int sl, int sr){
            if(i <= sl || i >= sr){
                return 0;
            }

            if(t[i] == 0){
                return 0;
            }

            int a = 0;
            if(i - 1 == sl){
                a = max(0, en[i - 1] - l + 1);
            }
            else{
                a = en[i - 1] - st[i - 1] + 1;
            }

            int b = 0;
            if(i + 1 == sr){
                b = max(0, r - st[i + 1] + 1);
            }
            else{
                b = en[i + 1] - st[i + 1] + 1;
            }

            return a + b;
        };

        vector<int> ans;

        for(auto &q:queries){
            int l = q[0];
            int r = q[1];

            int sl = seg[l];
            int sr = seg[r];

            if(sr - sl < 2){
                ans.push_back(one);
                continue;
            }

            int cur = 0;
            cur = max(cur, calc(sl + 1, l, r, sl, sr));
            cur = max(cur, calc(sr - 1, l, r, sl, sr));

            if(sl + 2 <= sr - 2){
                cur = max(cur, rmq(sl + 2, sr - 2));
            }

            ans.push_back(one + cur);
        }

        return ans;
    }
};
