class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        vector<int> p;
        vector<int> t;

        int n = arr.size();

        for(int i = 0; i < n; i++){
            if(arr[i] == 'P'){
                p.push_back(i);
            }
            else{
                t.push_back(i);
            }
        }

        int i = 0;
        int j = 0;
        int res = 0;

        while(i < p.size() && j < t.size()){
            if(abs(p[i] - t[j]) <= k){
                res++;
                i++;
                j++;
            }
            else if(t[j] < p[i]){
                j++;
            }
            else{
                i++;
            }
        }

        return res;
    }
};
