/* BST Node Structure
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
    long long merge(vector<int>& arr, vector<int>& temp, int l, int m, int r){
        int i = l, j = m + 1, k = l;
        long long ans = 0;

        while(i <= m && j <= r){
            if(arr[i] <= arr[j]){
                temp[k++] = arr[i++];
            }
            else{
                temp[k++] = arr[j++];
                ans += m - i + 1;
            }
        }

        while(i <= m){
            temp[k++] = arr[i++];
        }

        while(j <= r){
            temp[k++] = arr[j++];
        }

        for(int i = l; i <= r; i++){
            arr[i] = temp[i];
        }

        return ans;
    }
    
    long long mergeSort(vector<int>& arr, vector<int>& temp, int l, int r){
        if(l >= r){
            return 0;
        }

        int m = l + (r - l) / 2;
        long long ans = mergeSort(arr, temp, l, m);
        ans += mergeSort(arr, temp, m + 1, r);
        ans += merge(arr, temp, l, m, r);

        return ans;
    }
    
    void inorder(Node* root, vector<int>& arr){
        if(root == NULL){
            return;
        }

        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }


    int pairsViolatingBST(Node *root) {
        // code here
        vector<int> arr;
        inorder(root, arr);

        vector<int> temp(arr.size());
        return mergeSort(arr, temp, 0, arr.size() - 1);
    }
};
