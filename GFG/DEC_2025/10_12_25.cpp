class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        long long int s_n = ((n *1LL * (n + 1)) / 2);
        long long int s_n2 = ((n * 1LL * (n + 1) * (2 * n + 1)) / 6);
        
        long long int s = 0;
        long long int s_2 = 0;
        for(int i = 0; i < n; i++){
            s += arr[i];
            s_2 += (long long) arr[i] * (long long) arr[i];
        }
        
        long long v1 = s - s_n;
        long long v2 = s_2 - s_n2;
        
        v2 = v2 / v1;
        
        return { (int)((v1 + v2) / 2), (int)(((v1 + v2) / 2) - v1)};
    }
};
