class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {}
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this; // "node" is basically the pointer which calls the insert function essentially root. 
        for (auto c : word){
            c -= 'a';
            if (node -> next[c] == NULL){
                node -> next[c] = new Trie(); // Insert if no other path exists
            }
            node = node -> next[c];
        }
        node -> words += 1; // This shows another "word" has been added.
    }
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for (auto c : word){
            c -= 'a';
            if (node -> next[c] == NULL) { return false; }
            node = node -> next[c];
        }
        return (node -> words > 0);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        // Move till no characters left to process or no link to go
        Trie* node = this;
        for (auto c : prefix){
            c -= 'a';
            if (node -> next[c] == NULL) { return false; }
            node = node -> next[c];
        }
        return true;
    }

private:
    Trie* next[26] = {};
    int words = 0; 
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
