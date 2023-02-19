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
    vector<vector<int>> ans;
    
    void solution(TreeNode* root, int level){
        if(root == nullptr)
            return;
        
        if(ans.size() == level)
            ans.push_back(vector<int>());
        
        ans[level].push_back(root->val);
        solution(root->right, level+1);
        solution(root->left, level+1);
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        solution(root, 0);
        
        for(int i = 0; i < ans.size(); i += 2){
            reverse(ans[i].begin(), ans[i].end());
        }
        
        return ans;
    }
};