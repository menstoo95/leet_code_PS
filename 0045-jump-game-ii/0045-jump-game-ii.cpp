class Solution {
public:
    int jump(vector<int> nums) {
        int n = nums.size();
        vector<int> dp(n, 10002);
        dp[n-1] = 0;

        for(int i = n-2; i >= 0; i--){
            for(int j = 1; j <= nums[i]; j++){
                dp[i] = min(dp[i], dp[min(n - 1, i + j)] + 1);
            }
        }

        return dp[0];
    }
};