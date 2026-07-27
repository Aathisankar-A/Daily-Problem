/* Structure of Binary Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    int i;
    unordered_map<int,int> mp;

    Node *build(vector<int> &pre, vector<int> &preMirror, int l, int r){
        if(i >= pre.size() || l > r)
            return NULL;

        Node *root = new Node(pre[i++]);

        if(l == r || i >= pre.size())
            return root;

        int idx = mp[pre[i]];

        root->left = build(pre, preMirror, idx, r);
        root->right = build(pre, preMirror, l + 1, idx - 1);

        return root;
    }
    
    Node *constructBinaryTree(vector<int> &pre, vector<int> &preMirror) {
        // code here
        int n = pre.size();
        i = 0;
        mp.clear();

        for(int j = 0; j < n; j++)
            mp[preMirror[j]] = j;

        return build(pre, preMirror, 0, n - 1);
    }
};
