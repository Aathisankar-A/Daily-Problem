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
    void inorder(Node* root, vector<int>& a){
        if(root == NULL){
            return;
        }
    
        inorder(root->left, a);
        a.push_back(root->data);
        inorder(root->right, a);
    }
        
    vector<int> findCommon(Node* r1, Node* r2) {
        // code here
        vector<int> a, b, ans;

        inorder(r1, a);
        inorder(r2, b);

        int i = 0, j = 0;

        while(i < a.size() && j < b.size()){
            if(a[i] == b[j]){
                ans.push_back(a[i]);
                i++;
                j++;
            }
            else if(a[i] < b[j]){
                i++;
            }
            else{
                j++;
            }
        }

        return ans;
    }
};
