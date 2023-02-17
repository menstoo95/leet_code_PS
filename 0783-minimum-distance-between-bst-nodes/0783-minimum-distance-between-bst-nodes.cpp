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
    void f(TreeNode* root, int& minD, int& prev) {
        if (root == nullptr)
            return;
        
        f(root -> left, minD, prev);

        if (prev != -1) {
            minD = min(minD, root -> val - prev);
        }
        prev = root -> val;
        
        f(root -> right, minD, prev);
        
    }
    
    int minDiffInBST(TreeNode* root) {
        int minD = 0x3f3f3f3f, prev = -1;
        
        f(root, minD, prev);
        return minD;
    }
};