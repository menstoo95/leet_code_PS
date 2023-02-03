class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n = s.size(), ans = 0;
        while(s.find("01") != string::npos){
            for(int i = 0; i < n-1; i++){
                if(s.substr(i,2) == "01"){
                    swap(s[i],s[i+1]);
                    i++;
                 }
            }
            ans++;
        }
        
        return ans;
    }
};

