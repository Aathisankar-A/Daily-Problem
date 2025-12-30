class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        vector<int> count(n, 0);

        priority_queue<int, vector<int>, greater<int>> freeRoom;
        for(int i = 0; i < n; i++){
            freeRoom.push(i);
        }

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> used;

        for(auto &m : meetings){
            long long start = m[0];
            long long end = m[1];

            while(!used.empty() && used.top().first <= start){
                freeRoom.push(used.top().second);
                used.pop();
            }

            long long dur = end - start;
            int room;
            long long begin;

            if(!freeRoom.empty()){
                room = freeRoom.top();
                freeRoom.pop();
                begin = start;
            }
            else{
                auto it = used.top();
                used.pop();
                room = it.second;
                begin = it.first;
            }

            count[room]++;
            used.push({begin + dur, room});
        }

        int res = 0;
        for(int i = 1; i < n; i++){
            if(count[i] > count[res]){
                res = i;
            }
        }
        return res;
    }
};
