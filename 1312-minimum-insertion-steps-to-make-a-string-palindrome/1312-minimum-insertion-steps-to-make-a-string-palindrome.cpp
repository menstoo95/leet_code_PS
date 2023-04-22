class Solution {
public:
    int dp[501][501], n;
    int lps(string& s, int n1, int n2)
    {
        if (n1 == 0 || n2 == 0) {
            return 0;
        }
        if (dp[n1][n2] != -1) {
            return dp[n1][n2];
        }
        if (s[n1 - 1] == s[n - n2]) {
            return dp[n1][n2] = 1 + lps(s, n1 - 1, n2 - 1);
        }
        else {
            return dp[n1][n2] = max(lps(s, n1 - 1, n2),
                                    lps(s, n1, n2 - 1));
        }
    }
    
    int minInsertions(string s) {
        n = s.size();
        memset(dp, -1, sizeof dp);
        
        return n - lps(s,n,n);
    }
};