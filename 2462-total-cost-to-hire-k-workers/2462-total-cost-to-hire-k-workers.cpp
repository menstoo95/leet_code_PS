class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<long long, vector<long long>, greater<long long>> pq1, pq2;
        long long l = 0, r = costs.size()-1, cnt = 0, ans = 0;
        cout << costs.size() << endl;
        while(l < candidates && cnt < costs.size()){
            pq1.push(costs[l++]);
            cnt++;
        }
        
        while(r >= costs.size()-candidates && cnt < costs.size()){
            pq2.push(costs[r--]);
            cnt++;
        }
        
        while(k){
            int a = 0x3f3f3f3f, b = 0x3f3f3f3f;
            if(pq1.size()) a = pq1.top();
            if(pq2.size()) b = pq2.top();
            
            if(a > b){
                ans += b;
                pq2.pop();
                if(l <= r && cnt < costs.size()){
                    pq2.push(costs[r--]);
                    cnt++;
                }
            }
            else{
                ans += a;
                pq1.pop();
                if(l <= r && cnt < costs.size()){
                    pq1.push(costs[l++]);
                    cnt++;
                }
            }
            k--;
        }
        
        
        return ans;
    }
};