class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        
        for(int i = nums.size()-1; i >= 2; i--){
            int l = 0, r = i-1;
            
            while(l < r){
                if(nums[l] + nums[r] > nums[i]){
                    ans += r-l;
                    r--;
                }
                else
                    l++;
            }
        }
        
        return ans;
    }
};