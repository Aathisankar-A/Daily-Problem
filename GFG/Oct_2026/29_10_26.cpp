class Solution {
  public:
    int minComputation(vector<int> &files) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq(files.begin(), files.end());
        int ans = 0;

        while(pq.size() > 1){
            int a = pq.top();
            pq.pop();

            int b = pq.top();
            pq.pop();

            int sum = a + b;
            ans += sum;

            pq.push(sum);
        }

        return ans;
    }
};
