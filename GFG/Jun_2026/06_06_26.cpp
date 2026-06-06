class Solution {
  public:
    int numOfWays(int n, int m) {
        // code here
        long long N = 1LL * n * m;

        long long attacks =
            4LL * ((long long)(n - 1) * (m - 2) +
                   (long long)(n - 2) * (m - 1));

        return (int)(N * (N - 1) - attacks);
    }
};
