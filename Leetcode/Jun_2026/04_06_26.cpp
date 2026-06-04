class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int res = 0;

        for(int i = num1; i <= num2; i++){
            int temp = i;
            vector<int> v;

            while(temp > 0){
                v.push_back(temp % 10);
                temp = temp / 10;
            }
            int len = v.size();
            for(int j = 1; j < len - 1; j++){
                bool a = (v[j] > v[j - 1] && v[j] > v[j+1]);
                bool b = (v[j] < v[j - 1] && v[j] < v[j + 1]);
                if(a || b){
                    res++;
                }
            }
        }
        return res;
    }
};
