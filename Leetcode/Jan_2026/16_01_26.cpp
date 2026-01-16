class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        vector<int> h = hFences;
        vector<int> v = vFences;

        h.push_back(1);
        h.push_back(m);
        v.push_back(1);
        v.push_back(n);

        sort(h.begin(), h.end());
        sort(v.begin(), v.end());

        unordered_set<int> hGaps;
        int hs = h.size();
        for(int i = 0; i < hs; i++){
            for(int j = i + 1; j < hs; j++){
                hGaps.insert(h[j] - h[i]);
            }
        }

        long long maxSide = -1;
        int vs = v.size();
        for(int i = 0; i < vs; i++){
            for(int j = i + 1; j < vs; j++){
                int gap = v[j] - v[i];
                if(hGaps.count(gap)){
                    if(gap > maxSide) maxSide = gap;
                }
            }
        }

        if(maxSide == -1) return -1;

        long long MOD = 1000000007;
        return (int)((maxSide * maxSide) % MOD);
    }
};
