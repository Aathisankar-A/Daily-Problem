/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    bool find(Node* root, int x, string &s){
        if(root == NULL){
            return false;
        }

        if(root->data == x){
            return true;
        }

        s.push_back('L');
        if(find(root->left, x, s)){
            return true;
        }
        s.pop_back();

        s.push_back('R');
        if(find(root->right, x, s)){
            return true;
        }
        s.pop_back();

        return false;
    }
    
    int numberOfTurns(Node* root, int p, int q) {
        // code here
        string a, b;

        find(root, p, a);
        find(root, q, b);

        int i = 0;

        while(i < a.size() && i < b.size() && a[i] == b[i]){
            i++;
        }

        string path;

        for(int j = a.size() - 1; j >= i; j--){
            path += a[j];
        }

        for(int j = i; j < b.size(); j++){
            path += b[j];
        }

        int ans = 0;

        for(int j = 1; j < path.size(); j++){
            if(path[j] != path[j - 1]){
                ans++;
            }
        }

        return ans == 0 ? -1 : ans;
    }
};
