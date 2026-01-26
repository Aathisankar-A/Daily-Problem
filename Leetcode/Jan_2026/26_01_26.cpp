class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> res;

        int mn = INT_MAX;
        int diff;

        for(int i = 0; i < n-1; i++){
            diff = abs(arr[i] - arr[i+1]);
            if(mn > diff){
                mn = diff;
            }
        }

        for(int i = 0; i < n-1; i++){
            if(abs(arr[i] - arr[i+1]) == mn){
                res.push_back({arr[i], arr[i+1]});
            }
        }
        return res;
    }
};
