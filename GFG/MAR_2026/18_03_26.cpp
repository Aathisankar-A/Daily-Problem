/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int moves = 0;
    
    int dfs(Node* root){
        if(root == NULL)
            return 0;
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        moves += abs(left) + abs(right);
        
        return root->data + left + right - 1;
    }
    
    int distCandy(Node* root) {
        // code here
        moves = 0;
        
        dfs(root);
        
        return moves;
    }
};
