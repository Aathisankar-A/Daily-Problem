class TrieNode{
public:
    bool isWord;
    TrieNode* child[26];

    TrieNode(){
        isWord = 0;
        for(int i = 0; i < 26; i++){
            child[i] = 0;
        }
    }
};

class Solution {
  public:
    int countSubs(string& s) {
        // code here
        TrieNode* head = new TrieNode();
        int cnt = 0;
    
        for(int i = 0; i < s.length(); i++){
            TrieNode* temp = head;
    
            for(int j = i; j < s.length(); j++){
                if(temp->child[s[j] - 'a'] == 0){
                    temp->child[s[j] - 'a'] = new TrieNode();
                    temp->isWord = 1;
                    cnt++;
                }
                temp = temp->child[s[j] - 'a'];
            }
        }
    
        return cnt;
    }
};
