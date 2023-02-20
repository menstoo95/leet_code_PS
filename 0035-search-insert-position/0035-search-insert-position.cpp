class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int r = nums.size()-1, l = 0;
	
        while(l <= r){
            int mid = (l+r)/2;

            if(nums[mid] > target)
                r = mid-1;
            else if(nums[mid] < target)
                l = mid+1;
            else
                return mid;
        }

        return l;
    }
};