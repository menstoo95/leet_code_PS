class Solution {
public:
    int dp[38] = {0,1,1};
    
    int memo(int n){
        if(n <= 0)
            return 0;
        if(dp[n])
            return dp[n];
        return dp[n] = memo(n-2) + memo(n-1) + memo(n-3);
    }

    int tribonacci(int n) {
        return memo(n);
    }
};