class Solution {
  public:
    void sortIt(vector<int>& arr) {
        // code here
        sort(arr.begin(), arr.end(), [](int a, int b){
            bool a_odd = a % 2;
            bool b_odd = b % 2;

            if(a_odd && b_odd)
                return a > b;
                
            if(!a_odd && !b_odd)
                return a < b;
                
            return a_odd;
        });
    }
};
