/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* build(vector<int> arr, int s, int e){
        if(s > e)
            return nullptr;
        
        int mid = (s+e)/2;
        
        TreeNode* ans = new TreeNode(arr[mid]);
        ans->left = build(arr, s, mid-1);
        ans->right = build(arr, mid+1, e);
        
        return ans;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> arr;
        
        while(head != nullptr){
            arr.push_back(head->val);
            head = head->next;
        }
        
        return build(arr, 0, arr.size()-1);
    }
    
};