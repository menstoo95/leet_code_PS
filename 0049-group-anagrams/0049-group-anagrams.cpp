class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hs;
        vector<vector<string>> ans;
        for(auto c : strs){
            string s = c;
            sort(s.begin(), s.end());
            hs[s].push_back(c);
        }

        for(auto s : hs)
            ans.push_back(s.second);

        return ans;
    }
};