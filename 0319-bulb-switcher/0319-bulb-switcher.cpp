class Solution {
public:
    int bulbSwitch(int n) {
        int ans = 0;
        int k = 3;
        while(n > 0){
            n -= k;
            k += 2;
            ans++;
        }
        
        return ans;
    }
};