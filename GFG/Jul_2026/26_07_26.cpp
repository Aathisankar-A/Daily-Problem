class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        vector<vector<int>> ans;
        
        int i = 0, cnt = 1;

        while(i < n){
            vector<int> v;

            for(int j = 0; j < cnt && i < n; j++, i++)
                v.push_back(arr[i]);

            sort(v.begin(), v.end());
            ans.push_back(v);

            cnt *= 2;
        }

        return ans;
    }
};
