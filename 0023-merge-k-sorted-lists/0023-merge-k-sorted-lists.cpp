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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int N = lists.size();

        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for(int i =0;i <N ;i++){
            if(lists[i] != nullptr){
                pq.push(lists[i]);
            }
        }
        while(!pq.empty()){
            ListNode* node = pq.top();
            pq.pop();
            temp->next = node;
            temp = temp->next;
            if(node->next != nullptr){
                pq.push(node->next);
            }
        }
        return ans->next;
    }
};