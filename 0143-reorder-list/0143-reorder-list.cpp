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
    ListNode* rev(ListNode* temp){
        ListNode* prev = nullptr;
        ListNode* curr = temp;
        ListNode* forw = nullptr;
        while(curr != nullptr){
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = nullptr;

        ListNode* temp2 = rev(slow);

        ListNode* temp1 = head;
        ListNode* forw1 = nullptr;
        ListNode* forw2 = nullptr;

        while(temp1 != nullptr ){
            forw1 = temp1->next;
            temp1->next = temp2;
            temp1 = forw1;
            if(temp1 == nullptr){
                break;
            }
            forw2 = temp2->next;
            temp2->next = temp1;
            temp2 = forw2;
        }
    }
};