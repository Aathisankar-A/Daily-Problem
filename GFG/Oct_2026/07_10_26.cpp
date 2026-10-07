/* Node Structure
class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = nullptr;
        right = nullptr;
    }
}
*/

class Solution {
  public:
    int cnt = 0;
    int ans = INT_MIN;
    
    int solve(Node *root){
        if(root == NULL){
            return INT_MIN;
        }
    
        if(root->left == NULL && root->right == NULL){
            cnt++;
            return root->data;
        }
    
        int l = solve(root->left);
        int r = solve(root->right);
    
        if(root->left != NULL && root->right != NULL){
            ans = max(ans, l + root->data + r);
            return root->data + max(l, r);
        }
    
        if(root->left != NULL){
            return root->data + l;
        }
    
        return root->data + r;
    }

    int maxPathSum(Node *root) {
        // code here
        solve(root);

        if(cnt < 2){
            return -1;
        }

        return ans;
    }
};
