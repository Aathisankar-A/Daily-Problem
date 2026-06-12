class Solution {
  public:
    bool kSubstr(string &s, int k) {
        // code here
        int n = s.size();

        if(n % k != 0){
            return false;
        }

        unordered_map<string, int> freq;

        int blocks = n / k;
        int mxFreq = 0;

        for(int i = 0; i < n; i += k){
            string part = s.substr(i, k);

            freq[part]++;
            mxFreq = max(mxFreq, freq[part]);
        }

        return mxFreq >= blocks - 1;
    }
};
