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
    int size(ListNode* node){
        int res = 0;
        
        while(node != nullptr){
            res++;
            node = node->next;
        }

        return res;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int length = size(head);

        if(length < k)
            return head;
        
        int cnt = 0;
        ListNode* cur = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while(cur != nullptr && cnt < k){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            cnt++;
        }

        if(next != nullptr)
            head->next = reverseKGroup(next, k);
        
        return prev;
    }
};