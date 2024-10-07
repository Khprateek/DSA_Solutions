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

 // LEVEL ORDER TRAVERSAL

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int ans = 0;
        while(!q.empty()){
            int n = q.size();
            int l =INT_MAX; int r= INT_MIN;
            int minPos = q.front().second;
            for(int i =0; i<n; i++){
                TreeNode* node = q.front().first;
                int pos = q.front().second - minPos;
                q.pop();
                r = max(r,pos);
                l = min(l,pos);
                if(node->left != nullptr){
                    q.push({node->left,2*pos-1});
                }
                if(node->right != nullptr){
                    q.push({node->right,2*pos});
                }
            }
            ans = max(ans,(r-l+1));
        }
        return ans;
    }
};