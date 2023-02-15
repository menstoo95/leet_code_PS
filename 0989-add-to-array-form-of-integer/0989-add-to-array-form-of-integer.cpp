class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int idx = num.size()-1, carry = 0, sum = 0;
        
        while(idx >= 0){
            sum = num[idx] + (k%10) + carry;
            num[idx] = sum % 10;
            carry = sum / 10;
            k /= 10;
            idx--;
        }
        
        while(k){
            sum = (k%10) + carry;
            num.insert(num.begin(), sum%10);
            carry = sum / 10;
            k /= 10;
        }
        
        if(carry)
            num.insert(num.begin(), 1);
            
        

        return num;
    }
};