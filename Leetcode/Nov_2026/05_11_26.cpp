class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt = 0;
        for(int x : arr1){
            bool flag = true;
            for(int y : arr2){
                flag &= (abs(x - y) > d);
            }
            cnt += flag;
        }
        return cnt;
    }
};
