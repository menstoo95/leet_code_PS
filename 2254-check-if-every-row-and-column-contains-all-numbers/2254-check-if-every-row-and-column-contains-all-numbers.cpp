class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            unordered_map<int,int> r, c;
            
            for(int j = 0; j < n; j++){
                r[matrix[i][j]]++;
                c[matrix[j][i]]++;
            }

            if(r.size() != n || c.size() != n)
                return false;
        }

        return true;
    }
};