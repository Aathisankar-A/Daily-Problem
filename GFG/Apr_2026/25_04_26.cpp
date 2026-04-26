class Solution {
  public:
    vector<int> reducePairs(vector<int>& arr) {
        // code here
        vector<int> ans;
        ans.push_back(arr[0]);

        int i = 1;

        while(i < arr.size()){
            int curr = arr[i];
            bool removed = false;

            while(!ans.empty() && ((ans.back() > 0 && curr < 0) || (ans.back() < 0 && curr > 0))){
                
                if(abs(ans.back()) < abs(curr)){
                    ans.pop_back();
                }
                else if(abs(ans.back()) == abs(curr)){
                    ans.pop_back();
                    removed = true;
                    break;
                }
                else{
                    removed = true;
                    break;
                }
            }

            if(!removed){
                ans.push_back(curr);
            }

            i++;
        }

        return ans;
    }
};
