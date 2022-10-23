class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int s_sum = 0, n = nums.size();
        unordered_set st(nums.begin(), nums.end());
        
        for(int e : st) s_sum += e;
        vector<int> ans = {-s_sum, (1 + n) * n / 2 - s_sum};
        for(int e : nums) ans[0] += e;
        
        return ans;
    }
};