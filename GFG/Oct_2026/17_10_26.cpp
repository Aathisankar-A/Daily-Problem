class Solution {
  public:
    bool isItPossible(string &s1, string &s2) {
        // code here
        if(s1.length() != s2.length())
                    return false;

        int n = s1.length();
        int countA = 0, countB = 0;

        for(int i = 0; i < n; i++){
            char ch1 = s1[i];
            char ch2 = s2[i];

            if(ch1 == 'A')
                countA++;
            else if(ch1 == 'B')
                countB++;

            if(ch2 == 'A')
                countA--;
            else if(ch2 == 'B')
                countB--;

            if(countA > 0)
                return false;

            if(countB < 0)
                return false;

            if(countB > 0 && countA < 0)
                return false;
        }

        return true;

    }
};
