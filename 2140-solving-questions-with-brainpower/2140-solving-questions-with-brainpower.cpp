class Solution {
public:
    long long dp[200001];
    
    long long mostPoints(vector<vector<int>>& questions) {
        for (int i = questions.size() - 1; i >= 0; i--)
            dp[i] = max(questions[i][0] + dp[questions[i][1] + i + 1], dp[i + 1]);
        
        return dp[0];
    }
};