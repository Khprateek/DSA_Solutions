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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        int f = 0;
        ListNode* prev1;
        ListNode* prev2;
        while(l1 != nullptr && l2 != nullptr){

            int s = (l1->val) + (l2->val) + f;
            int rem = s%10;
            f = s/10;
            l1->val = rem;
            prev1 = l1;
            l1 = l1->next;
            prev2 = l2;
            l2 = l2->next;
        }
        if(l2 == nullptr){
            while(l1 != nullptr){
            int s = (l1->val) + f;
            int rem = s%10;
            f = s/10;
            l1->val = rem;
            prev1 = l1;
            l1 = l1->next;
            }
            if( f != 0){
                ListNode* new1 = new ListNode(f);
                prev1->next = new1;
            }
        }
        else if( l1 == nullptr){
            prev1->next = l2;
            while(l2 != nullptr){
            int s = (l2->val) + f;
            int rem = s%10;
            f = s/10;
            l2->val = rem;
            prev2 = l2;
            l2 = l2->next;
            if( f != 0){
                ListNode* new1 = new ListNode(f);
                prev2->next = new1;
            }
            }
            
        }
        return head;
    }
};