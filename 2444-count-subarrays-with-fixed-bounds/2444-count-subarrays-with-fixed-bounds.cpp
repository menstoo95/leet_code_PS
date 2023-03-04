class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long res = 0;
        bool min_found = false, max_found = false;
        int leftbound = 0, min_start = 0, max_start = 0;
        
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            if(num < minK || num > maxK){
                min_found = false;
                max_found = false;
                leftbound = i+1;
            }
            if(num == minK){
                min_found = true;
                min_start = i;
            }
            if(num == maxK){
                max_found = true;
                max_start = i;
            }
            if(min_found && max_found){
                res += (min(min_start, max_start) - leftbound + 1);
            }
        }
        return res;
    }
};