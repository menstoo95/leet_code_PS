#define ll long long
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        
        ll n = x, comp = 0;
        
        while(n){
            comp = comp*10 + n%10;
            n /= 10;
        }
        
        return x == comp;
    }
};