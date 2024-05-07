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
    ListNode* reverseList(ListNode* head){
        ListNode* dummy = NULL;
        while(head ! =NULL){
            ListNode* temp = head->next;
            head->next = dummy;
            dummy = head;
            head = temp;
        } 
        return dummy;
    }
    ListNode* doubleIt(ListNode* head) {
        head = reverseList(head);
        int carry = 0;
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL){
            int num = temp->val;
            temp->val = (num*2+carry)%10;
            carry = (num*2+carry)/10;
            prev = temp;
            temp = temp->next;
        }

        if(carry){
            ListNode* n = new ListNode(carry);
            prev->next = n;
        }
        head = reverseList(head);
        return head;
    }
};