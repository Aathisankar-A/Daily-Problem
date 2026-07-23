/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void rec(Node *root, vector<int> &ans){
        if(!root)
            return;
        
        ans.push_back(root->data);
        
        rec(root->left, ans);
        rec(root->right, ans);
    }
    
    vector<int> preOrder(Node* root) {
        // code here
        vector<int> ans;
        rec(root, ans);
        
        return ans;
    }
};
