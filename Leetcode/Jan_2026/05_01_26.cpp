class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        long long sum = 0;
        int neg = 0;
        int mn = INT_MAX;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int x = matrix[i][j];
                if(x < 0)
                    neg++;

                sum += abs(x);
                mn = min(mn, abs(x));
            }
        }
        if(neg % 2){
            sum -= 2 * mn;
        }
        return sum;
    }
};
