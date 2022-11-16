class Solution {
public:
    int guessNumber(int n) {
        long long l = 1, r = n;
        
        while(1){
            long long mid = (l+r) / 2;
            
            long long res = guess(mid);
            
            if (res == 0){ 
                return (int)mid;
            }
            else if (res == 1){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
    }
};