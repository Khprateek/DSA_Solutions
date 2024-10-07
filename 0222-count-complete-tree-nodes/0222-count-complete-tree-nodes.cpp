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
    int leftheight(TreeNode* root){
        if(root == nullptr) return 0;
        int cnt =1;
        while(root->left != nullptr){
            cnt++;
            root = root->left;
        }
        return cnt;
    }
    int rightheight(TreeNode* root){
        if(root == nullptr) return 0;
        int cnt =1;
        while(root->right != nullptr){
            cnt++;
            root = root->right;
        }
        return cnt;
    }

public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        int lh = leftheight(root);
        if(leftheight(root) == rightheight(root)) return pow(2,lh)-1;
        else{
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};