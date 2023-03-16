
class Solution {
public:
    TreeNode* constructTree(vector<int>& inorder, vector<int>& postorder, int in_start, int in_end, int post_start, int post_end, unordered_map<int, int>& inorder_map){
        if(in_start > in_end){
            return NULL;
        }
        int root_val = postorder[post_end];
        TreeNode* root = new TreeNode(root_val);
        int root_index = inorder_map[root_val];
        int left_subtree_size = root_index - in_start;
        root->left = constructTree(inorder, postorder, in_start, root_index-1, post_start, post_start+left_subtree_size-1, inorder_map);
        root->right = constructTree(inorder, postorder, root_index+1, in_end, post_start+left_subtree_size, post_end-1, inorder_map);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> inorder_map;
        for(int i=0; i<n; i++){
            inorder_map[inorder[i]] = i;
        }
        
        return constructTree(inorder, postorder, 0, n-1, 0, n-1, inorder_map);
    }
};