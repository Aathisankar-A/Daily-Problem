class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());

        long long sum = 0;
        int count = 0;
        int i = happiness.size() - 1;

        while (k-- && i >= 0) {
            long long curr = happiness[i] - count;
            if (curr <= 0) break;
            sum += curr;
            count++;
            i--;
        }
        return sum;
    }
};
