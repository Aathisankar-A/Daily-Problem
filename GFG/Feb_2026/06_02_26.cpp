class Solution {
  public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        // code here.
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());

        int i = 0, j = 0, l = 0;
        int da = a.size(), db = b.size(), dc = c.size();

        int minDiff = INT_MAX;
        int minSum = INT_MAX;
        vector<int> ans(3);

        while(i < da && j < db && l < dc){
            int x = a[i];
            int y = b[j];
            int z = c[l];

            int mx = max(x, max(y, z));
            int mn = min(x, min(y, z));
            int diff = mx - mn;
            int sum = x + y + z;

            if(diff < minDiff || (diff == minDiff && sum < minSum)){
                minDiff = diff;
                minSum = sum;
                ans = {x, y, z};
            }

            if(mn == x) i++;
            else if(mn == y) j++;
            else l++;
        }

        sort(ans.begin(), ans.end(), greater<int>());
        return ans;
    }
};
