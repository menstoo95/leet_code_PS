class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0, zero = 0, idx = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0)
                zero++;
            
            while(zero > 1){
                if(nums[idx] == 0)
                    zero--;
                idx++;
            }
            ans = max(ans, i-idx);
        }

        return ans;
    }
};