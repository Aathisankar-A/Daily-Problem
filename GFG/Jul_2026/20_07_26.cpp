class TrieNode{
public:
    TrieNode* child[26];
    int cnt;

    TrieNode(){
        cnt = 0;
        for(int i = 0; i < 26; i++) child[i] = NULL;
    }
};

class Solution {
  public:
    void insert(TrieNode* root, string &s){
        TrieNode* node = root;
        for(char c : s){
            int id = c - 'a';
            if(node->child[id] == NULL)
                node->child[id] = new TrieNode();

            node = node->child[id];
            node->cnt++;
        }
    }

    string getPrefix(TrieNode* root, string &s){
        TrieNode* node = root;
        string ans = "";

        for(char c : s){
            int id = c - 'a';
            node = node->child[id];
            ans += c;
            if(node->cnt == 1)
                break;
        }

        return ans;
    }
    
    vector<string> findPrefixes(vector<string>& arr) {
        // code here
        TrieNode* root = new TrieNode();

        for(string &s : arr)
            insert(root, s);

        vector<string> ans;

        for(string &s : arr)
            ans.push_back(getPrefix(root, s));

        return ans;
    }
};
