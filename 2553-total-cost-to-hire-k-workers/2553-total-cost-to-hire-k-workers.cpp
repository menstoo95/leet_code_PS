class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> pqf, pqb;
        int l = 0, r = costs.size()-1;
        long long ans = 0ll;
        while(k--){
            while(pqf.size() < candidates && l <= r){
                pqf.push(costs[l]);
                l++;
            }
            while(pqb.size() < candidates && l <= r){
                pqb.push(costs[r]);
                r--;
            }

            int front = pqf.size() ? pqf.top() : 0x3f3f3f3f, back = pqb.size() ? pqb.top() : 0x3f3f3f3f;
            
            if(front <= back){
                ans += front;
                pqf.pop();
            }
            else{
                ans += back;
                pqb.pop();
            }
        }

        return ans;
    }
};