/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* pre = NULL;
        Node* suc = NULL;
        
        while (root != NULL) {
            if (key < root->data) {
                suc = root;
                root = root->left;
            }
            else if (key > root->data) {
                pre = root;
                root = root->right;
            }
            else {
                if (root->left != NULL) {
                    Node* temp = root->left;
                    while (temp->right != NULL) {
                        temp = temp->right;
                    }
                    pre = temp;
                }
                if (root->right != NULL) {
                    Node* temp = root->right;
                    while (temp->left != NULL) {
                        temp = temp->left;
                    }
                    suc = temp;
                }
                break;
            }
        }
        
        return {pre, suc};
    }
};
