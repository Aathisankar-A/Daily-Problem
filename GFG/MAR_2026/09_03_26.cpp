class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        int n = s.size();

        vector<int> maxIdx(n);
        int idx = n - 1;

        for(int i = n - 1; i >= 0; i--){
            if(s[i] > s[idx])
                idx = i;

            maxIdx[i] = idx;
        }

        for(int i = 0; i < n; i++){
            if(s[i] < s[maxIdx[i]]){
                swap(s[i], s[maxIdx[i]]);
                break;
            }
        }

        return s;
    }
};
