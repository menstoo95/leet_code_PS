class Solution {
public:
    int partitionString(string s) {
        vector<int> hs(26);
        int ans = 1;
        
        for(auto c : s){
            if(hs[c-'a']){
                fill(hs.begin(), hs.end(), 0);
                ans++;
            }
            hs[c-'a']++;
            
        }
        
        return ans;
    }
};