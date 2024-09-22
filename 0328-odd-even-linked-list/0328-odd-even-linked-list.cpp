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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* temp = head;
        ListNode* last =head;
        int cnt = 0;
        while(last->next != nullptr){
            cnt++;
            last = last->next;
        }
        ListNode* temp2 = last;
        if(cnt & 1){
            last = head->next; 
        }
        bool act = false;
        while(temp != last){
            temp2->next = temp->next;
            temp->next = temp->next->next;
            temp2 = temp2->next;
            temp = temp->next;
            temp2->next = nullptr;
            act = !act;
        }
        return head;
    }
};