class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> a,b;
        unordered_set<int> c,d;
        vector<vector<int>> ans(2, vector<int>());
        
        for(auto n : nums1) a[n]++;
        for(auto n : nums2) b[n]++;
        
        for(auto n : nums1)
            if(!b[n])
                c.insert(n);
        
        for(auto n : nums2)
            if(!a[n])
                d.insert(n);
        
        for(auto n : c)
            ans[0].push_back(n);
        for(auto n : d)
            ans[1].push_back(n);
        
        return ans;
    }
};