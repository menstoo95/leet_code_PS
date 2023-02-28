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
    string serialize(TreeNode* node, unordered_map<string, vector<TreeNode*>>& hs) {
        if(node == nullptr)
            return "";
        
        string res = "(" + serialize(node->left, hs) + to_string(node->val) + serialize(node->right, hs) + ")";
        
        hs[res].push_back(node);
        
        return res;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*>> hs;
        vector<TreeNode*> ans;
        serialize(root, hs);
        
        for(auto it : hs)
            if(it.second.size() > 1)
                ans.push_back(it.second[0]);
        
        return ans;
    }
};