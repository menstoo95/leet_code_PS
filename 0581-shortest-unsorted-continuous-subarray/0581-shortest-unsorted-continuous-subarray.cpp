class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> tmp = nums;
        int l = 0, r = nums.size()-1;
        sort(tmp.begin(), tmp.end());
        
        while(l < nums.size() && tmp[l] == nums[l]) l++;
        while(r >= 0 && tmp[r] == nums[r]) r--;
        
        return r > l ? r-l+1 : 0;
    }
};