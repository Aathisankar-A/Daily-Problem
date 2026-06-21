class Solution {
  public:
    string chooseSwap(string &s) {
        // code here
        vector<int> firstPos(26, -1);

        for(int i = 0; i < s.size(); i++){

            if(firstPos[s[i] - 'a'] == -1){
                firstPos[s[i] - 'a'] = i;
            }
        }

        for(int i = 0; i < s.size(); i++){

            int curr = s[i] - 'a';

            for(int ch = 0; ch < curr; ch++){

                if(firstPos[ch] > i){

                    char c1 = s[i];
                    char c2 = char(ch + 'a');

                    for(char &c : s){

                        if(c == c1){
                            c = '#';
                        }
                        else if(c == c2){
                            c = c1;
                        }
                    }

                    for(char &c : s){

                        if(c == '#'){
                            c = c2;
                        }
                    }

                    return s;
                }
            }
        }

        return s;
    }
};
