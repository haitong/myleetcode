/*
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode(): is_word_(false), c_('\0') {
        for(int i=0; i < 26; i ++){
            children_[i] = NULL;
        }
    }
    
    TrieNode(char c): is_word_(false),c_(c){
        for(int i=0; i < 26; i ++){
            children_[i] = NULL;
        }        
    }
    
    inline bool isWord(){
        return is_word_;
    }
    
    inline void setWord(){
        is_word_ = true;
    }
    
    inline void setChildren(int index, TrieNode * child){
        children_[index] = child;
    }
    
    inline bool isChildrenExist(int index){
        return children_[index] != NULL;
    }
    
    inline TrieNode * getChildren(int index){
        return children_[index];
    }
    
    inline char getCharacter(){
        return c_;
    }
    
    inline char getChildrenCharacter(int index){
        assert(children_[index] == NULL);
        return children_[index]->getCharacter();
    }
    
private:
    bool is_word_;
    char c_;
    TrieNode * children_[26];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    inline int index(char c){
        return (int)(c - 'a');
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode * curr = root;
        for(int i = 0; i < s.size(); i ++){
            if(!curr->isChildrenExist(index(s[i]))){
                curr->setChildren(index(s[i]), new TrieNode(s[i]));
            }
            curr = curr->getChildren(index(s[i]));
        }
        curr->setWord();
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        if(root == NULL) return false;
        TrieNode * curr = root;
        for(int i=0 ; i < key.size(); i++){
            if(curr->isChildrenExist(index(key[i]))){
                curr = curr->getChildren(index(key[i]));
            }
            else return false;
        }
        return curr->isWord();
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        if(root == NULL) return false;
        TrieNode * curr = root;
        for(int i=0; i < prefix.size(); i++){
            if(curr->isChildrenExist(index(prefix[i]))){
                curr = curr->getChildren(index(prefix[i]));
            }
            else return false;
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
