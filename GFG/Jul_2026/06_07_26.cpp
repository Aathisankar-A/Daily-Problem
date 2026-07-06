class Solution {
  public:
    int maxPathSum(vector<int> &a, vector<int> &b) {
        // Code here
        int n = a.size();
        int m = b.size();

        int i = 0;
        int j = 0;
        
        long long s1 = 0;
        long long s2 = 0;
        
        long long ans = 0;

        while(i < n && j < m){
            if(a[i] < b[j]){
                s1 += a[i];
                i++;
            }
            else if(a[i] > b[j]){
                s2 += b[j];
                j++;
            }
            else{
                ans += max(s1, s2) + a[i];
                s1 = 0;
                s2 = 0;
                i++;
                j++;
            }
        }

        while(i < n){
            s1 += a[i];
            i++;
        }

        while(j < m){
            s2 += b[j];
            j++;
        }

        ans += max(s1, s2);

        return ans;
    }
};
