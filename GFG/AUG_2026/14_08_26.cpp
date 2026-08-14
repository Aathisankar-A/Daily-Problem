class Solution {
  public:
    bool isPossible(vector<int>& arr, int s, int x) {
        // code here
        if(x == 0) return true;

        vector<long long> v;
        long long sum = s;

        if(s <= x) v.push_back(s);

        for(int a : arr){
            long long num = sum + a;
            sum += num;

            if(num > x) break;

            v.push_back(num);
        }

        for(int i = v.size() - 1; i >= 0; i--){
            if(v[i] <= x){
                x -= v[i];
            }
        }

        return x == 0;
    }
};
