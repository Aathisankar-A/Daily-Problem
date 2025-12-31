/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* reverse(Node* head) {
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
    
    Node* addTwoLists(Node* head1, Node* head2) {
        // code here
        head1 = reverse(head1);
        head2 = reverse(head2);

        Node* dummy = new Node(0);
        Node* cur = dummy;

        int carry = 0;

        while(head1 || head2 || carry){
            int sum = carry;

            if(head1){
                sum += head1->data;
                head1 = head1->next;
            }

            if(head2){
                sum += head2->data;
                head2 = head2->next;
            }

            carry = sum / 10;
            cur->next = new Node(sum % 10);
            cur = cur->next;
        }

        Node* res = reverse(dummy->next);

        while(res && res->data == 0 && res->next){
            res = res->next;
        }

        return res;
    }
};
