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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<pair<int, ListNode*>> arr;

        for(auto a : lists){
            ListNode* tmp = a;
            
            while(tmp != nullptr){
                arr.push_back({tmp->val, tmp});
                tmp = tmp->next;
            }
        }
        
        if(!arr.size())
            return nullptr;
        
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < arr.size()-1; i++){
            arr[i].second->next = arr[i+1].second;
        }
        
        
        return arr[0].second;
    }
};