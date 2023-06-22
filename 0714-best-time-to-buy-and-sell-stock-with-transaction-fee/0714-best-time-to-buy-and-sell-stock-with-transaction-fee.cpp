class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int mini = prices[0], ans = 0;
        
        for(auto p : prices){
            if(p < mini)
                mini = p;
            else if(p > mini + fee){
                ans += p - mini - fee;
                mini = p - fee;
            }
        }
        
        return ans;
    }
};