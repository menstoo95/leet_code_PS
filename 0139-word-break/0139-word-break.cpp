class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        
        if(!st.size())
            return false;

        vector<bool> dp(s.size()+1);
        dp[0] = true;
        
        for(int i = 1; i <= s.size(); i++){
            for(int j = i-1; j >= 0; j--){
                if(dp[j]){
                    string word = s.substr(j,i-j);
                    if(st.find(word) != st.end()){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        for(auto a : dp)
            cout << a << " ";
        
        return dp[s.size()];
    }
};