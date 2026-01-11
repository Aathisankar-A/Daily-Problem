class Solution {
public:
    int area(vector<int>& heights){
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for(int i = 0; i <= n; i++){
            int currHeight;
            if(i == n)
                currHeight = 0;
            else
                currHeight = heights[i];

            while(!st.empty() && currHeight < heights[st.top()]){
                int h = heights[st.top()];
                st.pop();

                int w;
                if(st.empty())
                    w = i;
                else
                    w = i - st.top() - 1;

                maxArea = max(maxArea, h * w);
            }
            st.push(i);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0)
            return 0;

        int n = matrix[0].size();
        vector<int> hist(n, 0);
        int res = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1')
                    hist[j]++;
                else
                    hist[j] = 0;
            }
            res = max(res, area(hist));
        }
        return res;
    }
};
