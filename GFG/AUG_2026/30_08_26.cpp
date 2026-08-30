class Solution {
  public:
    vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank) {
        // code here
        int n = l.size();
        vector<int> pre(n);
        vector<int> ans;

        pre[0] = r[0] - l[0] + 1;

        for(int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + r[i] - l[i] + 1;

        for(int x : rank){
            int lo = 0;
            int hi = n - 1;

            while(lo < hi){
                int mid = lo + (hi - lo) / 2;

                if(pre[mid] >= x)
                    hi = mid;
                else
                    lo = mid + 1;
            }

            int prev = lo == 0 ? 0 : pre[lo - 1];
            ans.push_back(l[lo] + x - prev - 1);
        }

        return ans;
    }
};
