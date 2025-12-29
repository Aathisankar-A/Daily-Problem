class Solution {
public:
    int bestClosingTime(string customers) {
        int pen = 0;
        for(char c : customers){
            if(c == 'Y')
                pen++;
        }

        int best = pen;
        int res = 0;

        for(int i = 0; i < customers.size(); i++){
            if(customers[i] == 'Y')
                pen--;
            else
                pen++;

            if(pen < best){
                best = pen;
                res = i + 1;
            }
        }
        return res;
    }
};
