class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        // code here
        string temp = s1 + s1;

        if(temp.find(s2) != string::npos)
            return true;

        return false;
    }
};
