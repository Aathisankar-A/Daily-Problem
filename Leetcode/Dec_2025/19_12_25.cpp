class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& meet : meetings){
            int x = meet[0], y = meet[1], time = meet[2];
            adj[x].emplace_back(time, y);
            adj[y].emplace_back(time, x);
        }

        vector<int> know(n, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.emplace(0, 0);
        pq.emplace(0, firstPerson);
        
        vector<int> result;

        while (!pq.empty()){
            auto [time, person] = pq.top();
            pq.pop();
            if (know[person] <= time) 
                continue;
            
            know[person] = time;
            result.push_back(person);
            
            for (auto& [t, nei] : adj[person]) {
                if (know[nei] != INT_MAX || t < time) 
                    continue;
                pq.push({t, nei});  
            }
        }
        return result;
    }
};
