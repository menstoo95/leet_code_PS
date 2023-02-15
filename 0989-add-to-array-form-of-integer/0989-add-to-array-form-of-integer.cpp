class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        for(int i = num.size()-1; i >= 0; i--){
            k += num[i];
            num[i] = k % 10;
            k /= 10;
        }
        
        while(k){
            num.insert(num.begin(), k%10);
            k /= 10;
        }
        
        return num;
    }
};