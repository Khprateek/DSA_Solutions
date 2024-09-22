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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return head;
        int cnt = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            cnt++;
            temp = temp->next;
        }
        temp = head;
        int pos = cnt - n - 1;
        if(pos < 0){
            head = head->next;
            return head;
        }
        while(pos > 0){
            temp = temp->next;
            pos--;
        }
        if(temp->next != nullptr){
            temp->next = temp->next->next;
        }
        return head;
    }
};