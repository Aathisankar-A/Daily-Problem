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
    void solve(Node* root, int mx, int &ans){
        if(root == NULL){
            return;
        }

        ans = max(ans, mx - root->data);

        mx = max(mx, root->data);

        solve(root->left, mx, ans);
        solve(root->right, mx, ans);
    }
    
    int maxDiff(Node* root) {
        // code here
        int ans = INT_MIN;

        solve(root->left, root->data, ans);
        solve(root->right, root->data, ans);

        return ans;
    }
};
