class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for(int i = num; i >= 0; i--){
            int res = 0, tmp = i;
            while(tmp){
                res = res*10 + tmp%10;
                tmp /= 10;
            }
            if(res + i == num)
                return true;
        }
        
        return false;
    }
};