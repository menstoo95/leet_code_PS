class Solution {
public:
    int minimumPartition(string s, int k) {
        int n = to_string(k).size(), ans = 0, i = 0;
        
        while(i < s.size()){
            int nxt = n;
            if(stoi(s.substr(i, n)) > k)
                nxt = n-1;
            if(nxt <= 0)
                return -1;
            ans++;
            i += nxt;
        }
        
        return ans;
    }
};