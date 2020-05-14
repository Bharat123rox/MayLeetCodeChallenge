class Trie {
public:
    /** Initialize your data structure here. */
    Trie* children[26];
    bool isEnd = true;

    Trie() {
        for(int i = 0; i < 26; i++)
        {
            this->children[i] = NULL;
        }
        this->isEnd = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* cur = this;
        for(int i = 0; i < word.size(); i++)
        {
            int key = word[i] - 'a';
            if(!cur->children[key])
                cur->children[key] = new Trie();
            cur = cur->children[key];
        }
        cur->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* cur = this;
        if(!cur) return false;
        for(int i = 0; i < word.size(); i++)
        {
            int key = word[i] - 'a';
            if(!cur->children[key]) return false;
            cur = cur->children[key];
        }
        return (cur && cur->isEnd);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* cur = this;
        if(!cur) return false;
        for(int i = 0; i < prefix.size(); i++)
        {
            int key = prefix[i] - 'a';
            if(!cur->children[key]) return false;
            cur = cur->children[key];
        }
        return cur;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */