class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();

        sort(cost.begin(), cost.end(), greater<int>());

        int cnt = 0;

        for(int i = 0; i < n; i+=3){
            if(i+1 < n)
                cnt += cost[i] + cost[i+1];
            else
                cnt += cost[i];
        }
        return cnt;
    }
};
