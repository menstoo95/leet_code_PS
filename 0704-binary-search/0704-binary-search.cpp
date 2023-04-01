class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        
        return (ans < nums.size() && nums[ans] == target) ? ans : -1;
    }
};