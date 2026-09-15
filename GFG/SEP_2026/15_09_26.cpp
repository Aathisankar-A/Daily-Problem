/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    int getCount(Node *root, int k) {
        // code here
        vector<int>cost;
        queue<pair<Node*, int>>q;
        q.push({root, 1});

        while(!q.empty()){
            auto [node, level] = q.front();
            q.pop();

            if(!node->left && !node->right){
                cost.push_back(level);
            }

            if(node->left){
                q.push({node->left, level + 1});
            }

            if(node->right){
                q.push({node->right, level + 1});
            }
        }

        sort(cost.begin(), cost.end());

        int ans = 0;

        for(int x : cost){
            if(k < x)
                break;

            k -= x;
            ans++;
        }

        return ans;
    }
};
