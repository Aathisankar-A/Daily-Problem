/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = NULL;
    }
};
*/

class Solution {
  public:
    Node* reverse(Node* head){
        Node* prev = NULL;
        Node* cur = head;

        while(cur){
            Node* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
    
    bool isPalindrome(Node *head) {
        //  code here
        if(!head || !head->next)
            return true;

        Node* slow = head;
        Node* fast = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* second = reverse(slow->next);
        Node* first = head;

        while(second){
            if(first->data != second->data)
                return false;
            first = first->next;
            second = second->next;
        }
        return true;
    }
};
