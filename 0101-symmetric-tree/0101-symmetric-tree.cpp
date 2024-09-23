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
    private:
    bool comp(TreeNode* L, TreeNode* R){
        if(L == nullptr && R == nullptr) return true;
        if(L == nullptr || R == nullptr) return false;
        if(L->val != R->val) return false;
        if(comp(L->left, R->right) && comp(L->right, R->left)){
            return true;
        }
        return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(comp(root->left,root->right)) return true;
        else return false;
    }
};