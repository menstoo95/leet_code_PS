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
    int arr[10001];
    int sz = 1;
    
    void dfs(TreeNode* root, int dpt){
        if(root == nullptr)
            return;
        
        arr[dpt] += root->val;
        sz = max(sz, dpt);
        
        dfs(root->right, dpt+1);
        dfs(root->left, dpt+1);
        
    }
    
    int maxLevelSum(TreeNode* root) {
        memset(arr, 0, sizeof arr);
        dfs(root, 1);
        
        int maxi = -0x3f3f3f3f;
        for(int i = 1; i <= sz; i++){
            // cout << arr[i] << endl;
            maxi = max(maxi, arr[i]);
        }
        
        // cout << sz << " " << maxi << endl;
        
        for(int i = 1; i <= sz; i++)
            if(arr[i] == maxi)
                return i;
        
        return 1;
    }
};