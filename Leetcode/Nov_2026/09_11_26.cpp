class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;
        set<int> available;

        vector<int> cnt(k, 0);

        for(int i = 0; i < k; i++){
            available.insert(i);
        }

        for(int i = 0; i < arrival.size(); i++){
            while(!busy.empty() && busy.top().first <= arrival[i]){
                available.insert(busy.top().second);
                busy.pop();
            }

            if(available.empty()){
                continue;
            }

            auto it = available.lower_bound(i % k);

            if(it == available.end()){
                it = available.begin();
            }

            int id = *it;

            available.erase(it);

            cnt[id]++;

            busy.push({(long long)arrival[i] + load[i], id});
        }

        int mx = *max_element(cnt.begin(), cnt.end());

        vector<int> ans;

        for(int i = 0; i < k; i++){
            if(cnt[i] == mx){
                ans.push_back(i);
            }
        }

        return ans;
    }
};
