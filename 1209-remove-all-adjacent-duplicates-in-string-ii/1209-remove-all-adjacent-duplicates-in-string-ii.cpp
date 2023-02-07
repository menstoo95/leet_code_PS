class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        string ans;
        int cnt = 0;
        for(auto c : s){
            if(st.empty() || st.top().first != c)
                st.push({c, 0});
            if(++st.top().second == k)
                st.pop();
        }

        while(st.size()){
            for(int i = 0; i < st.top().second; i++){
                ans += st.top().first;
            }
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};