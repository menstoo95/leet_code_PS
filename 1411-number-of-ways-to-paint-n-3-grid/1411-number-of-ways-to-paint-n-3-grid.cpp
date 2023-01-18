/*
121 212 312
123 213 313
131 231 321
132 232 323

121 131 212 232 313 323
123 132 213 231 312 321

121 -> (212 232 313) * basecase 6 + (213 312) * basecase 6
123 -> (212 232) * basecase 6 + (231 312) * basecase 6
*/

class Solution {
public:   
    int numOfWays(int n) {
        long long pa1 = 6, pa2 = 6, mod = 1000000007;
        
        for(int i = 1; i < n; i++){
            long long tmp1 = (pa1 * 3) % mod + (pa2 * 2) % mod;
            long long tmp2 = (pa1 * 2) % mod + (pa2 * 2) % mod;
            pa1 = tmp1 % mod;
            pa2 = tmp2 % mod;
        }
        
        return (int)(pa1+pa2) % mod;
    }
};
