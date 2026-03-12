class Solution {
public:
    vector<int> dtob(int n){
        vector<int> b;

        while(n){
            b.push_back(n % 2);
            n = n / 2;
        }
        reverse(b.begin(), b.end());
        return b;
    }

    vector<int> subtract(vector<int> &a, vector<int> &b) {
        vector<int> res;
        int i = a.size() - 1;
        int j = b.size() - 1;
        int borrow = 0;

        while (i >= 0) {
            int valA = a[i--];
            int valB = (j >= 0) ? b[j--] : 0;

            int diff = valA - valB - borrow;

            if (diff < 0) {
                diff += 2;    // Borrow from the next higher bit
                borrow = 1;
            } else {
                borrow = 0;
            }

            res.push_back(diff);
        }

        // Remove leading zeros (e.g., 101 - 100 = 001 -> 1)
        while (res.size() > 1 && res.back() == 0) {
            res.pop_back();
        }

        reverse(res.begin(), res.end());
        return res;
    }

    int btod(const std::vector<int>& v) {
        int decimalValue = 0;
        for (int bit : v) {
            // Double the current total and add the next bit
            decimalValue = (decimalValue << 1) | bit; 
        }
        return decimalValue;
    }

    int bitwiseComplement(int n) {
        // n + x = 1;

        // n - 1 = -x;

        // 1 - n = x;

        if(!n) return !n;

        vector<int> b = dtob(n);
        vector<int> a(b.size(), 1);

        vector<int> c = subtract(a, b);

        return btod(c);
    }
};
