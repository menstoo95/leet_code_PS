class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        map<int,int> hs;
        vector<int> ans;
        for(auto n : nums)
            hs[n]++;
        
        for(auto h : hs){
            while(h.second--){
                ans.push_back(h.first);
            }
        }
        
        return ans;
    }
};