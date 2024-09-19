/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        if(root == nullptr) return ans;
        st1.push(root);
        while(!st1.empty()){
            TreeNode* front = st1.top();
            st1.pop();
            st2.push(front);
            if(front->left != nullptr){
                st1.push(front->left);
            }
            if(front->right != nullptr){
                st1.push(front->right);
            }
        }
        while(!st2.empty()){
            TreeNode* leaf = st2.top();
            st2.pop();
            ans.push_back(leaf->val);
        }
        return ans;
    }
};