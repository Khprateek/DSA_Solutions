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
        ListNode* temp = head;
        ListNode* prev = new ListNode(0);
        ListNode* head2 = prev;
        while(temp != nullptr && temp->next != nullptr){
            if(temp->val == temp->next->val){
                while(temp->val == temp->next->val){
                    temp = temp->next;
                    if(temp->next == nullptr){
                        break;
                    }
                }
                if(prev == nullptr){
                    prev = temp->next;
                }
                else{
                    prev->next = temp->next;
                }
                temp = temp->next;
            }
            else{
                prev->next = temp;
                prev = prev->next;
                temp = temp->next;
            }
        }
        return head2->next;
    }
};