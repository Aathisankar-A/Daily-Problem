class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();

        sort(capacity.begin(), capacity.end(), greater<int>());
        
        int sum = 0;
        for(int num : apple){
            sum += num;   
        }
        
        int cnt = 0;
        while(sum > 0){
            sum -= capacity[cnt++];
        }
        return cnt;
    }
};
