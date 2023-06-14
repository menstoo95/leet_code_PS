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
    int ans = 0x3f3f3f3f;
    TreeNode *prev = NULL;
    
    void hi(TreeNode *root) {
        if(root->left)
            hi(root->left);
        
        if(prev)
            ans = min(ans, abs(prev->val - root->val));
        
        prev = root;
        
        if(root->right)
            hi(root->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        
        hi(root);
        
        return ans;
    }
};