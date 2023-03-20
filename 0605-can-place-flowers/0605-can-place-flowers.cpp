class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int ans = 0;
        for(int i = 0; i < flowerbed.size(); i++){
            if(!flowerbed[i]){
                if((i == 0 || !flowerbed[i-1]) && (i == flowerbed.size()-1 || !flowerbed[i+1])){
                    flowerbed[i] = 1;
                    ans++;
                    if(ans >= n)
                        return true;
                }
            }
        }
        
        return ans >= n;
    }
};