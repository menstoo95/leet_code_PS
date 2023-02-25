class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> forward(prices.size()), backward(prices.size());
        
        int mini = prices[0], maxi = prices[prices.size()-1];
        for(int i = 1; i < prices.size(); i++){
            if(mini > prices[i])
                mini = prices[i];
            forward[i] = max(forward[i-1], prices[i]-mini);
        }
        
        for(int i = prices.size()-2; i >= 0; i--){
            if(maxi < prices[i])
                maxi = prices[i];
            backward[i] = max(backward[i+1], maxi-prices[i]);
        }
        
        int ans = -0x3f3f3f3f3f;
        for(int i = 0; i < prices.size(); i++){
            ans = max(ans, forward[i]+backward[i]);
        }
        
        return ans;
    }
};