class Solution {
public:
    int dp[1002][1002];
    
    string gcdOfStrings(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        cout << str1 + str2 << endl;
        return (str1 + str2 == str2 + str1) ? str1.substr(0, gcd(n, m)) : "";
    }
};