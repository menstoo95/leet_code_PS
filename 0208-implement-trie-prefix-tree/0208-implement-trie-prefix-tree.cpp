class Trie {
private:
    bool end = false;
    Trie* next[26];
    
public:
    Trie() {
        memset(next, 0, sizeof next);
        end = false;
    }

    void insert(string word) {
        Trie* node = this;
        
        for(char c : word){
            int cur = c-'a';
            
            if(node->next[cur] == nullptr)
                node->next[cur] = new Trie();
            
            node = node->next[cur]; 
        }
        node->end = true;
    }

    bool search(string word) {
        Trie* node = this;
        
        for(char c : word){
            int cur = c-'a';
            node = node->next[cur]; 
            
            if(node == nullptr)
                return false;
        }
        
        if(node->end)
            return true;
        
        return false;
    }

    bool startsWith(string prefix) {
        Trie* node = this;
        
        for(char c : prefix){
            int cur = c-'a';
            node = node->next[cur]; 
            
            if(node == nullptr)
                return false;
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */