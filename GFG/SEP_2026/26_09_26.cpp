class Solution {
  public:
    int minimumCost(int x, int s, int m, int l, int cs, int cm, int cl) {
        // code here
        int res = INT_MAX;

        for(int i = 0; i <= x / s + 1; i++){
            for(int j = 0; j <= x / m + 1; j++){
                int area = i * s + j * m;

                if(area >= x)
                    res = min(res, i * cs + j * cm);
                else{
                    int k = (x - area + l - 1) / l;
                    res = min(res, i * cs + j * cm + k * cl);
                }
            }
        }

        for(int k = 0; k <= x / l + 1; k++){
            int area = k * l;

            if(area >= x)
                res = min(res, k * cl);
        }

        return res;
    }
};
