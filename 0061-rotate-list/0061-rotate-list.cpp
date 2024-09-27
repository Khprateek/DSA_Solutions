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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* temp = head;
        int n = 0;
        while(temp->next != nullptr){
            n++;
            temp = temp->next;
        }
        n++;
        temp->next = head;
        k = k%n;
        n = n-k;
        for(int i = 0; i< n; i++){
            temp = temp->next;
        }
        ListNode* ans = temp->next;
        temp->next = nullptr;
        return ans;
    }
};