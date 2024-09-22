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
    bool isPalindrome(ListNode* head) {
        bool ans = true;
        vector<int> arr;
        if(head == nullptr) return false;
        ListNode* temp = head;
        while(temp != nullptr){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int n = arr.size();
        int l =0;
        int r = n-1;
        while(l <= r){
            if(arr[l] != arr[r]){
                ans = false;
                break;
            }
            l++;
            r--;
        }
        return ans;
    }
};