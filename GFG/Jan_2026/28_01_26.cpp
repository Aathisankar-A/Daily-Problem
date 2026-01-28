class Solution {
  public:
    void gen(vector<int>& a, int i, int end, long long sum, vector<long long>& v){
        if(i == end){
            v.push_back(sum);
            return;
        }
        gen(a, i + 1, end, sum, v);
        gen(a, i + 1, end, sum + a[i], v);
    }

    int countSubset(vector<int>& arr, int k){
        int n = arr.size();
        int mid = n / 2;

        vector<long long> left, right;

        gen(arr, 0, mid, 0, left);
        gen(arr, mid, n, 0, right);

        sort(right.begin(), right.end());

        int cnt = 0;

        for(long long x : left){
            long long need = k - x;
            cnt += upper_bound(right.begin(), right.end(), need) 
                 - lower_bound(right.begin(), right.end(), need);
        }

        return cnt;
    }
};
