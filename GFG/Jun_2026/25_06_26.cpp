class Solution {
  public:
    vector<int> ans;
    
    void find(int n, int last, int num){
        if(n == 0){
            ans.push_back(num);
            return;
        }

        for(int i = last + 1; i <= 9; i++){
            find(n - 1, i, num * 10 + i);
        }
    }

    
    vector<int> increasingNumbers(int n) {
        // code here
        if(n > 9){
            return {};
        }

        if(n == 1){
            ans.push_back(0);
        }

        find(n, 0, 0);

        return ans;
    }
};
