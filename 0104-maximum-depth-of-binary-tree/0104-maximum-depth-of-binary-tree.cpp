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
    int max_depth = 0;
    
    void in(TreeNode* root, int depths){
        if(root == nullptr){
            max_depth = max(max_depth, depths);
            return;
        }
        
        in(root->right, depths+1);
        in(root->left, depths+1);
        
        return;
    }
    int maxDepth(TreeNode* root) {
        in(root, 0);
        
        return max_depth;
    }
};