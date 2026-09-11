class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int cnt = 0;
        vector<int> freq(10, 0);

        for(int i : digits){
            freq[i]++;
        }

        for(int h = 1; h < 10; h++){
            if(freq[h] > 0){
                freq[h]--;

                for(int t = 0; t < 10; t++){
                    if(freq[t] > 0){
                        freq[t]--;

                        for(int o = 0; o < 10; o += 2){
                            if(freq[o] > 0){
                                cnt++;
                            }
                        }

                        freq[t]++;
                    }
                }

                freq[h]++;
            }
        }

        return cnt;
    }
};
