class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minp = 10001, ans = 0;
        
        for(auto p : prices){
            if(minp > p)
                minp = p;
            ans = max(ans, p-minp);
        }
        
        return ans;
    }
};