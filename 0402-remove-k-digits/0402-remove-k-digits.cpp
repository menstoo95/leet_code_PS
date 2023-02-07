class Solution {
public:
    string removeKdigits(string num, int k) {
        string st = "";
        
        for(auto c : num){
            while(st.size() && k && c < st.back())
                st.pop_back(), k--;
            if(st.size() || c != '0')
                st.push_back(c);
        }
        
        while(k && st.size())
            st.pop_back(), k--;
        
        return st == "" ? "0" : st;
    }
};