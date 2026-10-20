class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        for(int k = 1; k <= n; k++){
            if(n % k != 0)
                continue;

            vector<int> res;
            bool valid = true;

            for(int i = 0; i < n; i += k){
                int cnt = 0, pos = -1;

                for(int j = i; j < i + k; j++){
                    int nxt = (j + 1 == i + k) ? i : j + 1;

                    if(nums[j] > nums[nxt]){
                        cnt++;
                        pos = j;
                    }
                }

                if(cnt > 1){
                    valid = false;
                    break;
                }

                int st = (pos == -1) ? i : pos + 1;
                for(int j = 0; j < k; j++)
                    res.push_back(nums[i + (st - i + j) % k]);
            }

            if(valid && is_sorted(res.begin(), res.end()))
                ans += k;
        }

        return (int)ans;
    }
};
