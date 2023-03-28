class Solution {
public:
    int dp[366];
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        for(int i = 1; i < 366; i++){
            if(find(days.begin(), days.end(), i) == days.end())
                dp[i] = dp[i - 1];
            else
                dp[i] = min({dp[i - 1] + costs[0], dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]});
        }
        
        return dp[days.back()];
    }
};