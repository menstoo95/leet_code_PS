class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int ans = 0;
        sort(costs.begin(), costs.end());
        
        for(auto c : costs){
            if(coins-c >= 0){
                coins -= c;
                ans++;
            }
        }
        
        return ans;
    }
};