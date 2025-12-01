class TrieNode{
  public:
    TrieNode* child[2];
    int cnt;
    TrieNode(){
        child[0] = NULL;
        child[1] = NULL;
        cnt = 0;
    }
};


class Solution {
  public:
    void insert(TrieNode* root, int x){
        for(int i = 15; i >= 0; i--){
            int bit = (x >> i) & 1;
            
            if(root->child[bit] == NULL)
                root->child[bit] = new TrieNode();
                
            root = root->child[bit];
            root->cnt++;
        }
    }
    
    int query(TrieNode* root, int x, int k){
        int res = 0;
        
        for(int i = 15; i >= 0 && root; i--){
            int xb = (x >> i) & 1;
            int kb = (k >> i) & 1;

            if(kb){
                if(root->child[xb])
                    res += root->child[xb]->cnt;
                root = root->child[1 - xb];
            }
            else{
                root = root->child[xb];
            }
        }
        return res;
    }
    
    int cntPairs(vector<int>& arr, int k) {
        // code here
        TrieNode* root = new TrieNode();
        int ans = 0;

        for(int x : arr){
            ans += query(root, x, k);
            insert(root, x);
        }

        return ans;
    }
};
