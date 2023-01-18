class Solution {
public:
    int similarPairs(vector<string>& words) {
        unordered_map<int, int> hs;
        int ans = 0;
        for(auto s : words){
            int tmp = 0;
            
            for(auto c : s){
                tmp |= (1 << (c-'a'));
            }
            ans += hs[tmp]++;
        }
        
        return ans;
    }
};