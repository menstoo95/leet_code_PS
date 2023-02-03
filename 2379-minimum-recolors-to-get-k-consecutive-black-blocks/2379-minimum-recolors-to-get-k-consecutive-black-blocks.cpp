class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = 101;
        for(int i = 0; i <= blocks.size()-k; i++){
            int cnt = 0;
            for(int j = i; j < i+k; j++){
                if(blocks[j] == 'W')
                    cnt++;
            }
            ans = min(ans, cnt);
        }
        return ans;
    }
};