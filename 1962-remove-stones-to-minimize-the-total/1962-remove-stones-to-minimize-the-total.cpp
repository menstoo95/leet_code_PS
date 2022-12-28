class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<pair<int,int>> pq;
        int ans = 0;

        for(int i = 0; i < piles.size(); i++){
            pq.push({floor(piles[i] / 2), piles[i]});
            ans += piles[i];
        }
        
        while(k--){
            auto cur = pq.top();
            pq.pop();
            ans -= cur.first;
            pq.push({floor((cur.second-cur.first) / 2), cur.second-cur.first});
        }
        
        return ans;
    }   
};