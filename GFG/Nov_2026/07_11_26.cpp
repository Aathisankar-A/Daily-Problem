class Solution {
  public:
    vector<string> generateUsernames(vector<string> arr) {
        // code here
        int n = arr.size();
        map<string, int> mpp;

        for(int i = 0; i < n; i++){
            if(mpp.find(arr[i]) == mpp.end()){
                mpp[arr[i]] = 1;
            }
        }

        vector<string> ans;

        for(int i = 0; i < n; i++){
            string s = arr[i];

            if(mpp[s] == 1){
                ans.push_back(s);
                mpp[s]++;
            }
            else{
                for(int j = 1; j <= 1000; j++){
                    string tmp = s + to_string(j);

                    if(mpp.find(tmp) == mpp.end()){
                        ans.push_back(tmp);
                        mpp[tmp] = 1;
                        break;
                    }
                }
            }
        }

        return ans;
    }
};
