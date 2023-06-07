class Solution {
public:
    int minFlips(int a, int b, int c) {
        /*
            0100
            0010
            0111
            
            0101
            
            0010
            0110
            0101
            
            0011
            0001
        */
        int ans = 0;
        
        while(a||b||c){
            int aa = a%2, bb = b%2, cc = c%2;
            
            if(cc && !(aa + bb))
                ans += 1;
            else if(!cc)
                ans += (aa+bb);

            a /= 2;
            b /= 2;
            c /= 2;
        }
        
        return ans;
    }
};