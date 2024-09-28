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
    ListNode* rev(ListNode* head){
        ListNode* temp = head->next;
        ListNode* forw = temp->next;
        ListNode* aage = forw->next;
        forw->next = temp;
        temp->next = aage;
        return forw;
    }
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* temp = new ListNode(0);
        ListNode* copy = temp;
        temp->next = head;
        while(temp->next != nullptr && temp->next->next != nullptr){
            temp->next = rev(temp);
            temp = temp->next->next;
        }
        return copy->next;
    }
};