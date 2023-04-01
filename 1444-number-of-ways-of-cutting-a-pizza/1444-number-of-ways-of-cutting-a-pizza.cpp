class Solution {
public:
    const long long MOD = 1000000007;
    int dp[51][51][11], m, n;
    
    bool checker(vector<string>&pizza, int sr, int er, int sc, int ec)
    {
        for (int i = sr; i <= er; i++)
        {
            for (int j = sc; j <= ec; j++)
            {
                if (pizza[i][j] == 'A')
                    return true;
            }
        }
        return false;
    }
    
    int memo(vector<string>&pizza, int sr, int sc, int cuts)
    {
        if(cuts == 0)
            return 1;
        
        if(dp[sr][sc][cuts] != -1)
            return dp[sr][sc][cuts];

        long long ans = 0;

        for (int i = sr; i < m - 1; i++) 
        {
            bool up = checker(pizza, sr, i, sc, n - 1);
            bool down = checker(pizza, i + 1, m - 1, sc, n - 1);
            if (up && down)
            {
                int next =  (memo(pizza, i + 1, sc, cuts - 1));
                ans = (ans + next) % MOD;
            }
        }

        for (int j = sc; j < n - 1; j++)
        {
            bool left = checker(pizza, sr, m - 1, sc, j); 
            bool right = checker(pizza, sr, m - 1, j + 1, n - 1);
            if (left && right)
            {
                int next = memo(pizza, sr, j + 1, cuts - 1);
                ans = (ans + next) % MOD;
            }
        }

        return dp[sr][sc][cuts] = (int)ans;
    }
    
    int ways(vector<string>& pizza, int k) {
        m = pizza.size(), n = pizza[0].size();
        memset(dp, -1, sizeof dp);
        
        return memo(pizza, 0, 0, k-1);
    }
};