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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root != nullptr){
            q.push(root);
        }

        while(!q.empty()){
            int sozu = q.size();
            vector<int> level;

            for(int i = 0 ;i < sozu; i++){

                TreeNode *front = q.front();
                q.pop();
                level.push_back(front->val);

                if(front->left != nullptr){
                    q.push(front->left);
                }
                if(front->right != nullptr){
                    q.push(front->right);
                }
            }
            ans.push_back(level);
        }


        return ans;
    }
};