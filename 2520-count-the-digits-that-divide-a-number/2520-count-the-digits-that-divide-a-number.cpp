class Solution {
public:
    int countDigits(int num) {
        int ans = 0;
        int n = num;
        int a[10];
        memset(a, 0, sizeof a);
        
        while(n){
            int tmp = n % 10;
            if(num % tmp == 0){
                if(!a[tmp])
                    ans++;
            }
            n = n/10;
        }

        return ans;
    }
};