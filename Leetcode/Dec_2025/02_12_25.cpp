class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int> pointNum;
        const int mod = 1000000007;

        long long ans = 0;
        long long sum = 0;

        for(int i = 0; i < (int)points.size(); i++){
            int y = points[i][1];
            pointNum[y]++;
        }
        
        for(auto it = pointNum.begin(); it != pointNum.end(); it++){
            int pNum = it->second;

            long long edge = (long long)pNum * (pNum - 1) / 2;
            ans += edge * sum;
            sum += edge;
        }

        return ans % mod;
    }
};
