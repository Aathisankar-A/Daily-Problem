class Solution {
public:
    int reverse(int n){
        int rev = 0;
        while(n){
            rev = rev * 10 +(n % 10);
            n /= 10;
        }
        return rev;
    }
    
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();

        int res = INT_MAX;

        map<int, int> mp;
        
        for(int i = 0; i < n; i++){
            if(mp.find(nums[i]) != mp.end()){
                res = min(res, abs(i - mp[nums[i]]));   
            }
            int rev = reverse(nums[i]);
            mp[rev] = i;
        }
        
        if(res == INT_MAX)
            return -1;

        return res;
    }
};
