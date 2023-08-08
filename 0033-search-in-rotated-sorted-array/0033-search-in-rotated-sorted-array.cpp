class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        
        while(l < r){
            int mid = (l+r)/2;
            
            if(nums[mid] > nums[r])
                l = mid+1;
            else
                r = mid;
        }

        int k = l;
        l = 0, r = nums.size()-1;
        
        while(l <= r){
            int mid = (l+r)/2;
            int rotmid = (mid+k) % nums.size();
            
            if(nums[rotmid] < target)
                l = mid+1;
            else if(nums[rotmid] == target)
                return rotmid;
            else
                r = mid-1;
        }
        
        return -1;
    }
};