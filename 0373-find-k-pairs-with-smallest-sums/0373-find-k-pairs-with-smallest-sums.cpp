class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>> pq;
        vector<vector<int>> ans;

        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < nums2.size(); j++){
                int local_sum = nums1[i] + nums2[j];

                if(pq.size() < k){
                    pq.push({local_sum, {i, j}});
                }
                else if(pq.top().first > local_sum){
                    pq.pop();
                    pq.push({local_sum, {i, j}});
                }
                else if(pq.top().first < local_sum){
                    break;
                }
            }
        }

        while(k-- && !pq.empty()){
            auto tmp = pq.top();
            ans.push_back({nums1[tmp.second.first], nums2[tmp.second.second]});
            pq.pop();
        }

        return ans; 
    }
};