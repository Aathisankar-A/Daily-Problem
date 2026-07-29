class Solution {
public:
    long long get(vector<int> &f, long long k){
        long long w = 1;
        int len = 0;

        for(int i = 0; i < 26; i++){
            if(f[i] == 0) continue;

            len += f[i];
            long long n = len;
            long long r = f[i];

            if(r > n - r) r = n - r;

            long long c = 1;

            for(int j = 1; j <= r; j++){
                c = c * (n - j + 1) / j;

                if(c > k){
                    c = k + 1;
                    break;
                }
            }

            w *= c;

            if(w > k) return k + 1;
        }

        return w;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> f(26, 0);

        for(char c : s){
            f[c - 'a']++;
        }

        vector<int> h(26, 0);
        string mid = "";
        int m = 0;

        for(int i = 0; i < 26; i++){
            if(f[i] % 2){
                mid += char(i + 'a');
            }

            h[i] = f[i] / 2;
            m += h[i];
        }

        if(get(h, k) < k){
            return "";
        }

        string a = "";

        for(int i = 0; i < m; i++){
            for(int j = 0; j < 26; j++){
                if(h[j] == 0) continue;

                h[j]--;

                long long w = get(h, k);

                if(w >= k){
                    a += char(j + 'a');
                    break;
                }

                k -= w;
                h[j]++;
            }
        }

        string ans = a + mid;

        for(int i = m - 1; i >= 0; i--){
            ans += a[i];
        }

        return ans;
    }
};
