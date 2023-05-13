class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1, 0);
        dp[0] = 1;
        int mod = 1000000007, ans = 0;
        for(int i = 1; i <= high; i++){
            if(i >= zero)
                dp[i] = (dp[i]+dp[i-zero]) % mod;
            if(i >= one)
                dp[i] = (dp[i]+dp[i-one]) % mod;
            if(i >= low)
                ans = (ans + dp[i]) % mod;
        }
        
        return ans;
    }
};