class Solution {
public:
    string intToRoman(int num) {
        string ntor[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int rton[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        string ans;
        for(int i = 0; i < 13; i++){
            while(num >= rton[i]){
                ans += ntor[i];
                num -= rton[i];
            }
        }
        
        return ans;
    }
};