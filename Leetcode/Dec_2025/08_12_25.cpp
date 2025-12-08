class Solution {
public:
    int countTriples(int n) {
        vector<bool> isSq(n * n + 1, false);
        for (int i = 1; i <= n; i++) {
            isSq[i * i] = true;
        }
        
        int cnt = 0;
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                int sum = a * a + b * b;
                if (sum <= n * n && isSq[sum])
                    cnt++;
            }
        }
        return cnt;
    }
};
