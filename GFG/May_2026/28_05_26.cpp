/* Structure of binary tree node
class Node{
public:
    int data;
    Node* left, right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
}
*/
class Solution {
  public:
    void dfs(Node* root, int hd, map<int, int> &mp){
        if(root == nullptr){
            return;
        }

        mp[hd] += root->data;

        dfs(root->left, hd - 1, mp);
        dfs(root->right, hd + 1, mp);
    }

    vector<int> verticalSum(Node* root) {
        // code here
        map<int, int> mp;

        dfs(root, 0, mp);

        vector<int> ans;

        for(auto it : mp){
            ans.push_back(it.second);
        }

        return ans;
    }
};
