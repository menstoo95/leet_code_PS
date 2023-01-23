class Solution {
public:
    int longestIdealString(string s, int k) {
        unordered_map<char, int> hs;
        int ans = 0;
        
        for(char c : s){
            for(int j = -k; j <= k; j++){
                hs[c-'a'] = max(hs[c-'a'], hs[c+j-'a']);
            }
            hs[c-'a']++;
            ans = max(hs[c-'a'], ans);
        }
        
        return ans;
    }
};