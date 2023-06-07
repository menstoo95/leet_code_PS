class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cur = INT_MIN, ans = 0;
        
        for(int p : prices){            
            int a = cur, b = ans;
            cur = max(a, b - p);
            ans = max(b, a + p);
        }
        
        return ans;
    }
};

