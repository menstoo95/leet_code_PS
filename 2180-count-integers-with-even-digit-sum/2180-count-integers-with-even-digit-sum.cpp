class Solution {
public:
    int countEven(int num) {
        int ans = 0;
        for(int i = 1; i <= num; i++){
            int tmp = i, sum = 0;
            while(tmp){
                sum += tmp % 10;
                tmp /= 10;
            }
            if(!(sum&1))
                ans++;
        }
        return ans;
    }
};