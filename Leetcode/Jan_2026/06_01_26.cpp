/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;

        q.push(root);
        int mx = root->val;
        int lvl = 0;
        int res = 1;

        while(!q.empty()){
            int size = q.size();
            int sum = 0;
            lvl += 1;

            for(int i = 0; i < size; i++){
                TreeNode* top = q.front();
                q.pop();
                sum += top->val;

                if(top->left != nullptr)
                    q.push(top->left);
                if(top->right != nullptr)
                    q.push(top->right);
            }
            if(mx < sum){
                mx = sum;
                res = lvl;
            }
        }
        return res;
    }
};
