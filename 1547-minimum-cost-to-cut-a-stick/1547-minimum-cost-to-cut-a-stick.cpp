class Solution {
public:
    int dp[102][102];
    int cuts_copy[102];
    
    int cost(int i, int j) {
        if(j-i <= 1)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];
        
        int res = 0x3f3f3f3f;

        for(int mid = i+1; mid < j; mid++){
            res = min(res, cost(i, mid) + cost(mid, j) + (cuts_copy[j]-cuts_copy[i]));
        }
        
        return dp[i][j] = res;
    }
    
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        

        sort(cuts.begin(), cuts.end());
        memset(dp, -1, sizeof dp);
        
        for(int i = 0; i < cuts.size(); i++)
            cuts_copy[i] = cuts[i];
        

        return cost(0, cuts.size()-1);
    }
};

// dp[i][j] = min(dp[i][k] + dp[k][j]) + (j - i)
