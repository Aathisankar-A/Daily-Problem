/* Structure for Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    int dfs(Node *root)
    {
        if(!root)
        {
            return 0;
        }
        
        // if(root->left == nullptr && root->right == nullptr){
        //     int val = root->val;
        //     root->val = 0;
            
        //     return val;
        // }
        
        int a = dfs(root->left);
        int b = dfs(root->right);
        
        int t = root->data;
        
        root->data = a+b;
        
        return a+b+t;
    }
    
    void toSumTree(Node *root) {
        // code here
        dfs(root);
    }
};
