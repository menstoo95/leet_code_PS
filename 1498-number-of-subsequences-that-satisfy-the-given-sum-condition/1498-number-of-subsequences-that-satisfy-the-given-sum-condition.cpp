class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int ans = 0, n = nums.size(), l = 0, r = n - 1, mod = 1e9 + 7;
        vector<int> pows(n, 1);

        for (int i = 1 ; i < n ; ++i)
            pows[i] = pows[i - 1] * 2 % mod;
        
        sort(nums.begin(), nums.end());
        
        while (l <= r) {
            if(nums[l] + nums[r] <= target){
                ans = (ans + pows[r-l]) % mod;
                l++;
            }
            else
                r--;
        }
        
        return ans;
    }
};