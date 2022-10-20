#define ll long long
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        
        int n = x;
        unsigned int comp = 0;
        
        while(n){
            comp = comp*10 + n%10;
            n /= 10;
        }
        
        return x == comp;
    }
};