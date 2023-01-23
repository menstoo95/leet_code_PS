class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long zeros = 0;
        for(int n : nums){
            if(n && zeros != 0){
                ans += zeros * (zeros + 1) / 2;
                zeros = 0;
            }
            else if(n && !zeros)
                zeros = 0;
            else if(!n)
                zeros++;
        }
        
        ans += zeros * (zeros + 1) / 2;
        
        return ans;
    }
};