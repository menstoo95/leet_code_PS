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
    ListNode* partition(ListNode* head, int x) {
        ListNode *LH = nullptr, *LT = nullptr, *RH = nullptr, *RT = nullptr;
        while (head){
            if (head->val < x){
                if (LH == nullptr){
                    LH = head;
                    LT = head;
                }
                else{
                    LT->next = head;
                    LT = head;
                }
            }
            else{
                if (RH == nullptr){
                    RH = head;
                    RT = head;
                }
                else{
                    RT->next = head;
                    RT = head;
                }
            }
            head = head->next;
        }

        if (LH == nullptr && RH != nullptr){
            RT->next = nullptr;
            return RH;
        }
        else if (LH != nullptr && RH == nullptr)
        {
            LT->next = nullptr;
            return LH;
        }
        else if (LH && RH)
        {
            LT->next = RH;
            RT->next = nullptr;
        }
        return LH;
    }
};