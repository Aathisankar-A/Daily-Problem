class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;

        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 60; j++){
                if(__builtin_popcount(i) + __builtin_popcount(j) == turnedOn){
                    string hrs = to_string(i);
                    string mins = "";

                    if(j < 10){
                        mins = "0";
                    }
                    mins += to_string(j);

                    res.push_back(hrs + ":" + mins);
                }
            }
        }
        return res;
    }
};
