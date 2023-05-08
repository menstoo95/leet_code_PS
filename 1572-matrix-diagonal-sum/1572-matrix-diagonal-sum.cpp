class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size(), sum = 0;
        
        for(int i = 0; i < n; i++){
            int a = n-i-1;
            if(a == i){
                sum += mat[i][i];
            }
            else{
                sum += mat[i][i] + mat[i][a];
            }
        }
        
        return sum;
    }
};