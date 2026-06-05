class Solution {
  public:
    bool isPowerOfTwo(int n){
        return n > 0 && (n & (n - 1)) == 0;
    }
    
    string lexicographicallySmallest(string &s, int k) {
        // code here
        int n = s.size();

        if(isPowerOfTwo(n))
            k /= 2;
        else
            k *= 2;

        if(k > n || n - k <= 0)
            return "-1";

        int remove = k;
        string st;

        for(char ch : s){
            while(!st.empty() && remove > 0 && st.back() > ch){
                st.pop_back();
                remove--;
            }
            st.push_back(ch);
        }

        while(remove > 0){
            st.pop_back();
            remove--;
        }

        if(st.empty())
            return "-1";

        return st;
    }
};
