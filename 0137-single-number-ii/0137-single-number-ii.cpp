class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> hs;
        
        for(auto a : nums)
            hs[a]++;
        
        for(auto a : hs)
            if(a.second == 1)
                return a.first;
        
        return -1;
    }
};