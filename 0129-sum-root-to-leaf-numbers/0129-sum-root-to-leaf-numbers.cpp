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
    int ans = 0;
    
    void sumit(TreeNode* root, string res){
        if(root == nullptr)
            return;
        
        res += to_string(root->val);
        
        if(root->right == nullptr && root->left == nullptr){
            ans += stoi(res);
            return;
        }
        
        sumit(root->right, res);
        sumit(root->left, res);
        
        return;
    }
    
    int sumNumbers(TreeNode* root) {
        sumit(root, "");
        
        return ans;
    }
};