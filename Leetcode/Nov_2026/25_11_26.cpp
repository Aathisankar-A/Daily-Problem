class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 2;
        int start = 0;

        unordered_map<int, int> last;

        for(int end = 0; end < n; end++){
            int x = nums[end];

            for(int p = 2; p * p <= x; p++){
                if(x % p == 0){
                    while(x % p == 0){
                        x /= p;
                    }

                    if(last.count(p)){
                        start = max(start, last[p] + 1);
                    }

                    last[p] = end;
                }
            }

            if(x > 1){
                if(last.count(x)){
                    start = max(start, last[x] + 1);
                }

                last[x] = end;
            }

            ans = max(ans, end - start + 1);
        }

        return ans;
    }
};
