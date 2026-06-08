/* Structure of a Linked List node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node *rev(Node* head){
        Node *curr = head;
        Node *prev = nullptr;
        Node* temp = head;
        
        while(curr){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            
            head = curr;
            curr = temp;
        }
        return head;
    }
    
    Node *compute(Node *head) {
        // code here
        head = rev(head);
        
        Node* curr = head;
        Node* prev = head;
        int mx = head->data;
        
        while(curr){
            if(curr->data >= mx){
                mx = curr->data;
                prev = curr;
            }
            else{
                prev->next = curr->next;
            }
            
            curr = curr->next;
        }
        
        return rev(head);
    }
};
