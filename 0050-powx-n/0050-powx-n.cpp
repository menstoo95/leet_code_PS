class Solution {
public:
    double myPow(double x, int n) {
        double result = 1.0;
        long long power = n;
        if (n < 0) {
            power = -power;
            x = 1 / x;
        }
        while (power) {
            if (power & 1) result *= x;
            x *= x;
            power >>= 1;
        }
        return result;
    }
};