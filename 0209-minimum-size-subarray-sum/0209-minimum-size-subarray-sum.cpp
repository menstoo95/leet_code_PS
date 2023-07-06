class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, sum = 0, cnt = INT_MAX;
        
        while(j < nums.size()){
            sum += nums[j];
            while(sum >= target){
                cnt = min(cnt, j-i+1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        
        return cnt == INT_MAX ? 0 : cnt;
    }
};