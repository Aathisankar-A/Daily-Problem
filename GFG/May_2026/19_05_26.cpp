class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        vector<int> dist(1000, 1e9);

        queue<int> q;

        q.push(start);
        dist[start] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            if(node == end){
                return dist[node];
            }

            for(int num : arr){
                int newNode = (node * num) % 1000;

                if(dist[node] + 1 < dist[newNode]){
                    dist[newNode] = dist[node] + 1;
                    q.push(newNode);
                }
            }
        }

        return -1;
    }
};
