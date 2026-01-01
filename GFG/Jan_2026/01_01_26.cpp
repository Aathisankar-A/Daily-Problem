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
    int getLen(Node* head){
        Node* curr = head;
        int len = 0;
        
        while(curr != nullptr){
            len++;
            curr = curr -> next;
        }
        return len;
    }
    
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
        int n1 = getLen(head1);
        int n2 = getLen(head2);
        
        if(n1 < n2){
            Node* curr1 = head1;
            Node* curr2 = head2;
            
            int diff = n2 - n1;
            for(int i = 0; i < diff; i++)
                curr2 = curr2 -> next;
            
            while(curr1 != curr2){
                curr1 = curr1 -> next;
                curr2 = curr2 -> next;
            }
            return curr1;
        }
        
        Node* curr1 = head1;
        Node* curr2 = head2;
        
        int diff = n1 - n2;
        for(int i = 0; i < diff; i++)
            curr1 = curr1 -> next;
        
        while(curr1 != curr2){
            curr1 = curr1 -> next;
            curr2 = curr2 -> next;
        }
        
        return curr1;
    }
};
