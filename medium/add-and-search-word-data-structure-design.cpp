// NICE Question

class trie {
public:
    int words;
    trie* ref[26];
    trie() {
        words = 0;
        for (int i = 0; i < 26; i ++) ref[i] = NULL;
    }    
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {}
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        trie* node = root;
        for (auto& c : word){
            c -= 'a';
            if (node -> ref[c] == NULL) { node -> ref[c] = new trie(); }
            node = node -> ref[c];
        }
        node -> words += 1;
    }
        
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return trie_search(root, word.c_str());
    }
    
private:
    trie* root = new trie();
    bool trie_search (trie* root, const char* word){
        trie* node = root;
        for (int i = 0; word[i] && node; i ++) {
            if (word[i] != '.'){
                node = node -> ref[word[i] - 'a'];
            } else{
                trie* temp = node;
                for (int j = 0; j < 26; j ++){
                    node = temp -> ref[j];
                    if (trie_search(node, word + i + 1))
                        return true;
                }
            }
            // node = node -> ref[word[i] - 'a'];
        }
        return node && (node -> words);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
