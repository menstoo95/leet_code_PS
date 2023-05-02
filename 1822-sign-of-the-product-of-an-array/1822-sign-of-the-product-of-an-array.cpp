class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool sign = true;
        
        for(auto n : nums){
            if(n < 0)
                sign = !sign;
            else if(!n)
                return 0;
        }
        
        return sign ? 1 : -1;
    }
};