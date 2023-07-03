class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size())
            return false;
        
        if(s == goal){
            set<char> st;
            for(auto c : s)
                st.insert(c);

            return st.size() < s.size();
        }
        
        int l = 0, r = s.size()-1;

        while(l < s.size() && s[l] == goal[l])
            l++;
        
        while(r >= 0 && s[r] == goal[r])
            r--;
        
        if(l < r)
            swap(s[l], s[r]);
        cout << l << " " << r << endl;

        return s == goal;
    }
};