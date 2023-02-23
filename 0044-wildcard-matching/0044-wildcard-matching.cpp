class Solution {
public:
    bool dp[2001][2001];
    bool isMatch(string s, string p) {
        dp[0][0] = true;
        
        for(int i = 0; i < p.size(); i++){
            if(p[i] == '*')
                dp[0][i+1] = true;
            else
                break;
        }
        
        
        for(int i = 1; i <= s.size(); i++){
            for(int j = 1; j <= p.size(); j++){
                if(p[j-1] == '*')
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else
                    dp[i][j] = (s[i-1] == p[j-1] || p[j-1] == '?') && dp[i-1][j-1];
            }
        }
        
        return dp[s.size()][p.size()];
    }
};