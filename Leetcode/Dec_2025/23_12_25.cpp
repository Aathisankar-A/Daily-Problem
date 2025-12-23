class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());

        // min-heap: {endTime, value}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        int mx = 0;
        int res = 0; 

        for(auto &e : events){
            int start = e[0];
            int end = e[1];
            int val = e[2];

            while(!pq.empty() && pq.top().first < start){
                mx = max(mx, pq.top().second);
                pq.pop();
            }

            res = max(res, mx + val);
            res = max(res, val);

            pq.push({end, val});
        }

        return res;
    }
};
