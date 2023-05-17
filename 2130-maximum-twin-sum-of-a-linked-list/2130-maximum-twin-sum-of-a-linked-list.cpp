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
class Solution {
public:
    int pairSum(ListNode* head) {
        stack<ListNode*> st;
        ListNode* tmp = head;
        
        while(tmp != nullptr){
            st.push(tmp);
            tmp = tmp->next;
        }

        int maxi = 0;
        while(st.size() > st.size()/2){
            maxi = max(maxi, (head->val + st.top()->val));
            st.pop();
            head = head->next;
        }
        
        return maxi;
    }
};