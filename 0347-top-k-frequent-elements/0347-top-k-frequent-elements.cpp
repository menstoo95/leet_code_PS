class Solution {
public:
   static bool cmp(const pair<int,int> &a, const pair<int,int> &b){
        return a.second > b.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> hs;
        for(auto a : nums)
            hs[a]++;
        
        vector<int> ans;
        vector<pair<int,int>> tmp(hs.begin(), hs.end());
        
        sort(tmp.begin(), tmp.end(), cmp);
        
        for(int i = 0; i < k; i++)
            ans.push_back(tmp[i].first);
        
        return ans;
    }
};