unordered_map<char, int> hs;

bool cmp(string a, string b){
    int n = min(a.length(), b.length());
    for(int i = 0; i < n; i++){
        if(hs[a[i]] < hs[b[i]]){
            return true;
        }
        else if(hs[a[i]] > hs[b[i]]){
            return false;
        }
    }
    if(a.length() <= b.length()){
        return true;
    }
    return false;
}

class Solution {   
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i = 0; i < order.length(); i++)
            hs[order[i]] = i;

        vector<string> tmp = words;
        sort(tmp.begin(), tmp.end(), cmp);
        return tmp == words;
    }
};