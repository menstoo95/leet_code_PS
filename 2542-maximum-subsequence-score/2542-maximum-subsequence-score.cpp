class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> grd,rrd;
        long long ans = 0, sum = 0;
        
        for(int i = 0; i < nums1.size(); i++){
            grd.push_back({-nums2[i], nums1[i]});
        }
        
        sort(grd.begin(), grd.end());
        
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i < grd.size(); i++){
            pq.push(grd[i].second);
            sum += grd[i].second;
            
            if(k < pq.size()){
                sum -= pq.top();
                pq.pop();
            }
            
            if(k == pq.size())
                ans = max(ans, sum * -grd[i].first);
        }
        
        return ans;
    }
};