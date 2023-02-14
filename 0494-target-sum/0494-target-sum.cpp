class Solution {
public:
    int ans = 0;
    void bt(int sum, int idx, vector<int>& nums, int target){
        if(idx == nums.size()){
            if(target == sum)
                ans++;
        }
        else{
            bt(sum + nums[idx], idx+1, nums, target);
            bt(sum - nums[idx], idx+1, nums, target);
        }
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        bt(0, 0, nums, target);
        
        return ans;
    }
    
};