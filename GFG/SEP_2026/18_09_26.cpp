/* Binary Tree Node Structure
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; 
*/

class Solution {
  public:
    int absDiff(Node *root) {
        // code here
        int res = INT_MAX;
        int prev = -1;

        stack<Node*> st;
        Node* curr = root;

        while(curr || !st.empty()){
            while(curr){
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            if(prev != -1){
                res = min(res, curr->data - prev);
            }

            prev = curr->data;
            curr = curr->right;
        }

        return res;
    }
};
