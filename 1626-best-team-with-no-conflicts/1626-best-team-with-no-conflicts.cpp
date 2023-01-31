class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> p;
        for(int i = 0; i < ages.size(); i++)
            p.push_back({ages[i], scores[i]});
        sort(p.begin(), p.end(), greater<pair<int,int>>());
        
        vector<int> dp(ages.size());
        int ans = 0;
                
        for(int i = 0; i < p.size(); i++){
            dp[i] = p[i].second;
            for(int j = 0; j < i; j++){
                if(p[i].second <= p[j].second)
                    dp[i] = max(dp[i], dp[j]+p[i].second);
            }
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};