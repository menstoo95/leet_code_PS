class Solution {
public:
    int dp[502][502];
    
    int minDistance(string s, string p) {
        int diff = 0;
        for(int j = 1; j <= p.size(); j++)
            dp[0][j] = j;
        for(int i = 1; i <= s.size(); i++)
            dp[i][0] = i;
        
        for(int i = 1; i <= s.size(); i++){
            for(int j = 1; j <= p.size(); j++){
                if(s[i-1] == p[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
            }
        }

        
        return dp[s.size()][p.size()];
    }
};