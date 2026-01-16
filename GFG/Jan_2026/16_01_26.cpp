class Solution {
  public:
    int minMen(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<pair<int,int>> intervals;

        for(int i = 0; i < n; i++){
            if(arr[i] != -1){
                int l = max(0, i - arr[i]);
                int r = min(n - 1, i + arr[i]);
                intervals.push_back({l, r});
            }
        }

        sort(intervals.begin(), intervals.end());

        int res = 0;
        int idx = 0;
        int covered = 0;

        while(covered < n){
            int farthest = covered;
            while(idx < intervals.size() && intervals[idx].first <= covered){
                farthest = max(farthest, intervals[idx].second + 1);
                idx++;
            }
            if(farthest == covered) return -1;
            res++;
            covered = farthest;
        }

        return res;
    }
};
