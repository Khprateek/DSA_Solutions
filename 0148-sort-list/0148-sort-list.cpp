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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr) return head;
        priority_queue<int,vector<int>, greater<int>> pq;
        ListNode* temp = head;
        while(temp != nullptr){
            pq.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(!pq.empty()){
            int Nod = pq.top();
            pq.pop();
            temp->val = Nod;
            temp = temp->next;
        }
        return head;
    }
};