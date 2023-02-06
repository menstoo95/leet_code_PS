class Solution {
public:
    int arrangeCoins(int n) {
        long long l = 0, r = n, mid, sum;
        
        while (l <= r) {
            mid = l + (r - l) / 2;
            sum = mid * (mid + 1) / 2;
            
            if(sum == n)
                return mid;
            
            if(sum <= n)
                l = mid + 1;
            else
                r = mid - 1;
        }
        
        return r;
    }
};