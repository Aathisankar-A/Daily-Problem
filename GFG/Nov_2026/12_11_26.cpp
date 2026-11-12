/* Structure of a Binary Search Tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int minDiff(Node *root, int k) {
        // code here
        int ans = INT_MAX;

        while(root != NULL){
            ans = min(ans, abs(root->data - k));

            if(root->data == k){
                return 0;
            }
            else if(k < root->data){
                root = root->left;
            }
            else{
                root = root->right;
            }
        }

        return ans;
    }
};
