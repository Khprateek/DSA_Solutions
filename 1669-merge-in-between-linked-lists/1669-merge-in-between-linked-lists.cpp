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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode* temp = list1;
        ListNode* prev;
        int cnt=0;
        while(cnt < a){
            prev = temp;
            temp = temp->next;
            cnt++;
        }
        prev->next = list2;
        while(prev->next != NULL){
            prev = prev->next;
        }
        while(cnt <= b){
            temp = temp->next;
            cnt++;
        }
        prev->next = temp;

        return list1;
    }

};