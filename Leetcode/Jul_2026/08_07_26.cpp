class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int MOD = 1000000007;
        int n = s.size();

        vector<int> val;
        vector<int> pos;

        for(int i = 0; i < n; i++){
            if(s[i] != '0'){
                val.push_back(s[i] - '0');
                pos.push_back(i);
            }
        }

        int k = val.size();

        vector<int> p_sum(k+1);
        vector<int> p_num(k+1);

        p_sum[0] = 0;
        p_num[0] = 0;

        for(int i = 0; i < k; i++){
            p_sum[i+1] = p_sum[i] + val[i];
            p_num[i+1] = (1LL * p_num[i] * 10 + val[i]) % MOD;
        }

        vector<int> pow10(k+1);

        pow10[0] = 1;

        for(int i = 1; i <= k; i++){
            pow10[i] = (1LL * pow10[i-1] * 10) % MOD;
        }

        vector<int> nxt(n, -1);
        vector<int> pre(n, -1);

        int pt = k - 1;

        for(int i = n - 1; i >= 0; i--){
            if(pt >= 0 && pos[pt] == i){
                nxt[i] = pt;
                pt--;
            }
            else{
                if(i == n - 1)
                    nxt[i] = -1;
                else
                    nxt[i] = nxt[i + 1];
            }
        }

        pt = 0;

        for(int i = 0; i < n; i++){
            if(pt < k && pos[pt] == i){
                pre[i] = pt;
                pt++;
            }
            else{
                if(i == 0)
                    pre[i] = -1;
                else
                    pre[i] = pre[i - 1];
            }
        }

        vector<int> ans;
        int l, r;

        for(int i = 0; i < queries.size(); i++){
            l = queries[i][0];
            r = queries[i][1];

            int L = nxt[l];
            int R = pre[r];

            if(L == -1 || R == -1 || L > R){
                ans.push_back(0);
                continue;
            }

            long long sum = p_sum[R + 1] - p_sum[L];

            long long x = (p_num[R + 1] - (1LL * p_num[L] * pow10[R - L + 1]) % MOD + MOD) % MOD;

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};
