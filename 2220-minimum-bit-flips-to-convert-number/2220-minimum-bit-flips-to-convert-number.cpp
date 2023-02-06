class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0, res = start^goal;
        while(res){
            res = res&(res-1);
            ans++;
        }
        
        return ans;
    }
};