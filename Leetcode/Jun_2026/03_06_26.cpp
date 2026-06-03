class Solution {
public:
    int solve(vector<int>& start1, vector<int>& dur1,
              vector<int>& start2, vector<int>& dur2){

        int m = start2.size();

        vector<pair<int,int>> rides;

        for(int i = 0; i < m; i++){
            rides.push_back({start2[i], dur2[i]});
        }

        sort(rides.begin(), rides.end());

        vector<int> starts(m);

        vector<int> prefMinDur(m);
        vector<int> suffMinFinish(m);

        for(int i = 0; i < m; i++){
            starts[i] = rides[i].first;

            if(i == 0)
                prefMinDur[i] = rides[i].second;
            else
                prefMinDur[i] = min(prefMinDur[i - 1],
                                    rides[i].second);
        }

        for(int i = m - 1; i >= 0; i--){
            int val = rides[i].first + rides[i].second;

            if(i == m - 1)
                suffMinFinish[i] = val;
            else
                suffMinFinish[i] = min(suffMinFinish[i + 1], val);
        }

        int ans = INT_MAX;

        for(int i = 0; i < start1.size(); i++){
            int A = start1[i] + dur1[i];

            int idx = upper_bound(starts.begin(),
                                  starts.end(),
                                  A) - starts.begin();

            if(idx > 0){
                ans = min(ans,
                          A + prefMinDur[idx - 1]);
            }

            if(idx < m){
                ans = min(ans,
                          suffMinFinish[idx]);
            }
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int landToWater = solve(
            landStartTime,
            landDuration,
            waterStartTime,
            waterDuration
        );

        int waterToLand = solve(
            waterStartTime,
            waterDuration,
            landStartTime,
            landDuration
        );

        return min(landToWater, waterToLand);
    }
};
