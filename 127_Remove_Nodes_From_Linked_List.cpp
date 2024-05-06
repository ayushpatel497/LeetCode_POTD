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
private:
    ListNode* reverse(ListNode* ptr){
        ListNode *prev = NULL, *nexxt;
        while(ptr){
            nexxt = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = nexxt;
        }
        return prev;
    }
public:
    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);
        ListNode* prev = head;
        int maxx = head->val;
        while(head->next){
            int temp = head->next->val;
            if(maxx > temp) head->next = head->next->next;
            else head = head->next;
            maxx = max(maxx,temp);
        }
        return reverse(prev);
    }
};