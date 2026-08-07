class Solution {
public:
    string smallestNumber(string num, long long t) {
        long long tmp = t;

        for(int i = 2; i <= 9; i++){
            while(tmp % i == 0){
                tmp /= i;
            }
        }

        if(tmp > 1){
            return "-1";
        }

        int n = num.size();

        vector<long long> rem(n + 1);
        rem[0] = t;

        int pos = n - 1;

        for(int i = 0; i < n; i++){
            if(num[i] == '0'){
                pos = i;
                break;
            }

            rem[i + 1] = rem[i] / gcd(rem[i], (long long)(num[i] - '0'));
        }

        if(rem[n] == 1){
            return num;
        }

        for(int i = pos; i >= 0; i--){
            while(++num[i] <= '9'){
                long long cur = rem[i] / gcd(rem[i], (long long)(num[i] - '0'));

                int k = 9;

                for(int j = n - 1; j > i; j--){
                    while(cur % k){
                        k--;
                    }

                    cur /= k;
                    num[j] = k + '0';
                }

                if(cur == 1){
                    return num;
                }
            }
        }

        string ans;

        for(int i = 9; i > 1; i--){
            while(t % i == 0){
                ans += i + '0';
                t /= i;
            }
        }

        ans += string(max(n + 1 - (int)ans.size(), 0), '1');

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
