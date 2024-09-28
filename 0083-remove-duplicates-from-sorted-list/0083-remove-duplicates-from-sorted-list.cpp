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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* back = head;
        ListNode* forw = head;
        while(forw->next != nullptr){
            if(forw->val == forw->next->val){
                forw->next = forw->next->next;
            }
            else{
                forw = forw->next;
            }
        }
        return head;
    }
};