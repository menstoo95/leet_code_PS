class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool bulky = false, heavy = false;
        long long tmp = (long long)length * (long long)width * (long long)height;
        if(length >= 10000 || width >= 10000 || height >= 10000)
            bulky = true;
        if(tmp >= 1000000000)
            bulky = true;
        if(mass >= 100)
            heavy = true;
        
        if(bulky && heavy)
            return "Both";
        if(!bulky && !heavy)
            return "Neither";
        if(bulky && !heavy)
            return "Bulky";
        if(!bulky && heavy)
            return "Heavy";
        return "";
    }
};