/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    struct Info{
        int minVal, maxVal, size;
        bool isBST;
    };
    
    Info dfs(Node* root, int &maxSize){
        if(root == NULL)
            return {INT_MAX, INT_MIN, 0, true};
        
        Info left = dfs(root->left, maxSize);
        Info right = dfs(root->right, maxSize);
        
        Info curr;
        
        if(left.isBST && right.isBST && root->data > left.maxVal && root->data < right.minVal){
            
            curr.isBST = true;
            curr.size = left.size + right.size + 1;
            curr.minVal = min(root->data, left.minVal);
            curr.maxVal = max(root->data, right.maxVal);
            
            maxSize = max(maxSize, curr.size);
        }
        else{
            curr.isBST = false;
            curr.size = 0;
            curr.minVal = INT_MIN;
            curr.maxVal = INT_MAX;
        }
        
        return curr;
    }
    
    int largestBst(Node *root) {
        // Your code here
        int maxSize = 0;
        
        dfs(root, maxSize);
        
        return maxSize;
    }
};
