class Node{
public:
    int data;
    char ch;
    int idx;
    Node* left;
    Node* right;

    Node(int d, char c, int i){
        data = d;
        ch = c;
        idx = i;
        left = NULL;
        right = NULL;
    }
};

class cmp{
public:
    bool operator()(Node* a, Node* b){
        if(a->data == b->data)
            return a->idx > b->idx;
        return a->data > b->data;
    }
};

class Solution{
public:
    void preorder(Node* root, string temp, vector<string> &ans){
        if(!root)
            return;

        if(!root->left && !root->right){
            if(temp == "")
                ans.push_back("0");
            else
                ans.push_back(temp);
            return;
        }

        preorder(root->left, temp + "0", ans);
        preorder(root->right, temp + "1", ans);
    }

    vector<string> huffmanCodes(string &s, vector<int> f){
        int n = s.size();
        priority_queue<Node*, vector<Node*>, cmp> pq;

        for(int i = 0; i < n; i++){
            pq.push(new Node(f[i], s[i], i));
        }

        while(pq.size() > 1){
            Node* left = pq.top();
            pq.pop();

            Node* right = pq.top();
            pq.pop();

            Node* newNode = new Node(left->data + right->data, '$', min(left->idx, right->idx));
            newNode->left = left;
            newNode->right = right;

            pq.push(newNode);
        }

        Node* root = pq.top();
        vector<string> ans;

        preorder(root, "", ans);

        return ans;
    }
};
