class Solution {
public:
    int divide(long dividend, long divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        bool isneg = false;
        long long ans = 0;
        if(divisor < 0)
            isneg = !isneg;
        if(dividend < 0)
            isneg = !isneg;
        
        dividend = abs(dividend);
        divisor = abs(divisor);
        
        for(int i = 31; i >= 0; i--){
            if(divisor << i <= dividend){
                dividend -= divisor << i;
                ans += 1 << i;
            }
        }
        
        return isneg ? -ans : ans;
        // return ((long long)dividend / divisor) > INT_MAX ? INT_MAX : dividend / divisor;
    }
};