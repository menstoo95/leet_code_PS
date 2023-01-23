class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long zeros = 0;
        for(int n : nums){
            if(!n){
                zeros++;
                ans+=zeros;
            }
            else
                zeros = 0;
        }
                
        return ans;
    }
};