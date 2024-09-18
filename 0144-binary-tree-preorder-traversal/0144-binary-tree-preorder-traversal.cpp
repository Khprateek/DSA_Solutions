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

 // THIS IS A ITERATIVE OR SAY BFS TARVERSAL

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        if(root == nullptr) return ans;
        st.push(root);
        while(!st.empty()){
            TreeNode *front = st.top();
            st.pop();
            ans.push_back(front->val);
            if(front->right != nullptr){
                st.push(front->right);
            }
            if(front->left != nullptr){
                st.push(front->left);
            }
        }
        return ans;
    }
};