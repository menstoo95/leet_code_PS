class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int> hs;
        for(auto a : nums)
            hs[a]++;
        
        for(auto h : hs)
            if(h.second == 1)
                return h.first;
        
        return 0;
    }
};