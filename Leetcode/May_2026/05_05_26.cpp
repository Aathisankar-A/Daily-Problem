/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head -> next)  return head;

        ListNode* curr = head;
        int n = 1;

        while(curr -> next){
            n++;
            curr = curr -> next;
        }

        curr -> next = head;
        k = k % n;

        int steps = n - k - 1;
        curr = head;

        for(int i = 0; i < steps; i++){
            curr = curr -> next;
        }
        head = curr -> next;
        curr -> next = nullptr;
        return head;
    }
};
