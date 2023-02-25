class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2)
            return nums.size();
        int up = 1, down = 1;
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1])
                up = down+1;
            else if(nums[i] < nums[i-1])
                down = up+1;
        }
        
        return max(up, down);
    }
};

/*
up  down
1   1
2   1
2   3
4   3
4   3
4   3
4   5
4   5
4   5
6   5
6   7
*/