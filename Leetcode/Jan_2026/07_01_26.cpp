/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long res = LLONG_MIN;
    long long total = 0;

    long long dfs(TreeNode* root){
        if(root == nullptr)
            return 0;

        root->val += dfs(root->left) + dfs(root->right);
        return root->val;
    }

    long long helper(TreeNode* root){
        if(root == nullptr)
            return 0;

        long long sum = root->val;
        res = max(res, (total - sum) * sum);

        helper(root->left);
        helper(root->right);

        return sum;
    }

    int maxProduct(TreeNode* root){
        total = dfs(root);
        helper(root);
        return (int)(res % (long long)(1e9 + 7));
    }
};
