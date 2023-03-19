class WordDictionary{
private:
    bool end = false;
    WordDictionary* next[26];
    
public:
    WordDictionary(){
        memset(next, 0, sizeof next);
        end = false;
    }
    
    void addWord(string word){
        WordDictionary* node = this;
        
        for(char c : word){
            int cur = c-'a';
            
            if(node->next[cur] == nullptr)
                node->next[cur] = new WordDictionary();
            
            node = node->next[cur]; 
        }
        node->end = true;
    }
        
    bool search(string word){
        WordDictionary* node = this;
        
        for(int i = 0; i < word.size(); i++){
            char c = word[i];
            if(c == '.'){
                for(auto ch: node->next)
                    if(ch && ch->search(word.substr(i+1)))
                        return true;
                return false;
            }
            
            node = node->next[c - 'a']; 
            if(node == nullptr)
                return false;
        }
        
        return node && node->end;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */