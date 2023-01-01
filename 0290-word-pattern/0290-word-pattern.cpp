class Solution {
public:
    vector<string> split(string input, char delimiter) {
        vector<string> answer;
        stringstream ss(input);
        string temp;

        while (getline(ss, temp, delimiter)) {
            answer.push_back(temp);
        }

        return answer;
    }
    
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> p2i;
        unordered_map<string, int> w2i;
        
        istringstream in(s); 
        string word;
        
        int i = 0, n = pattern.size();
        
        for(word = ""; in >> word; i++){
            if(i == n || p2i[pattern[i]] != w2i[word]) 
                return false; 
            p2i[pattern[i]] = w2i[word] = i+1;
        }
        return i==n; 
    }
};