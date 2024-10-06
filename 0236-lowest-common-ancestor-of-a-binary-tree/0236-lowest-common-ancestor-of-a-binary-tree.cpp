/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    private:
    bool side(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr) return false;
        if(root == p || root == q) return true;
        return side(root->left,p,q) | side(root->right,p,q);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        if(root == p || root == q) return root;

        bool leftSide = side(root->left, p, q);
        bool rightSide = side(root->right, p, q);
        if (leftSide && rightSide) return root;


        else if(side(root->left,p,q)) return lowestCommonAncestor(root->left,p,q);
        return lowestCommonAncestor(root->right,p,q);
    }
};