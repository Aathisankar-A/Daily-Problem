/* Structure of binary tree Node
class Node {
    public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool areAnagrams(Node* root1, Node* root2) {
        // code here
        if(!root1 || !root2)
            return root1 == root2;

        queue<Node*> q1, q2;
        q1.push(root1);
        q2.push(root2);

        while(!q1.empty() && !q2.empty()){
            int n1 = q1.size();
            int n2 = q2.size();

            if(n1 != n2)
                return false;

            vector<int> a, b;

            for(int i = 0; i < n1; i++){
                Node* u = q1.front();
                q1.pop();

                a.push_back(u->data);

                if(u->left)
                    q1.push(u->left);

                if(u->right)
                    q1.push(u->right);
            }

            for(int i = 0; i < n2; i++){
                Node* u = q2.front();
                q2.pop();

                b.push_back(u->data);

                if(u->left)
                    q2.push(u->left);

                if(u->right)
                    q2.push(u->right);
            }

            sort(a.begin(), a.end());
            sort(b.begin(), b.end());

            if(a != b)
                return false;
        }

        return q1.empty() && q2.empty();
    }
};
