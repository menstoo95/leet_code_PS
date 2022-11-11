class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), ans = 0;
        vector<int> dp(n, 0);
        
        stack<int> st;
        
        for(int i = 0; i < n; i++){
            if(s[i] == '(')
                st.push(i);
            else{
                if(st.empty())
                    dp[i] = 0;
                else{
                    int idx = st.top();
                    st.pop();
                    
                    if(idx > 0)
                        dp[i] = dp[idx-1] + dp[i-1] + 2;
                    else
                        dp[i] = dp[i-1] + 2;
                }
            }
            ans = max(dp[i], ans);
        }
        
        return ans;
    }
};