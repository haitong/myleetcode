/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.
*/
class TrieNode {

public:

    char cc;

    bool isWord;

    TrieNode * children[26];

    TrieNode(): isWord(false){

        for(int i=0; i < 26; i ++){

            children[i] = nullptr;

        }

    }

    

    TrieNode(char c, bool b): cc(c), isWord(b){

        for(int i=0; i < 26; i ++){

            children[i] = nullptr;

        }        

    }

};



class WordDictionary {

public:

    WordDictionary() {

        root = new TrieNode;

    }

    // Adds a word into the data structure.

    void addWord(string word) {

        TrieNode * curr = root;

        for(int i=0; i < word.size(); i++){

            if(curr->children[word[i] - 'a'] == nullptr){

                curr->children[word[i]- 'a'] = new TrieNode(word[i], false);

            }

            curr = curr->children[word[i] - 'a'];

        }

        curr->isWord = true;

    }



    // Returns if the word is in the data structure. A word could

    // contain the dot character '.' to represent any one letter.

    bool search(string word) {

        return searchHelper(word, 0, root);

    }

private:

    TrieNode * root;

    bool searchHelper(const string& word, const int index, const TrieNode* curr){

        if(index >= word.size()) return false;

        if(curr == nullptr) return false;

        if(word[index] == '.'){

            for(int j=0; j < 26; j++){

                if(index == word.size() -1 && curr->children[j] != nullptr && curr->children[j]->isWord) return true;

                if(searchHelper(word, index+1, curr->children[j])) return true;

            }

        }

        else{

            for(int j=0; j < 26; j++){

                if(index == word.size() -1 && curr->children[j] != nullptr

                    && curr->children[j]->cc == word[index] && curr->children[j]->isWord) return true;

                if(curr->children[j] != nullptr && word[index] == curr->children[j]->cc 

                    && searchHelper(word, index+1, curr->children[j])) return true;

            }    

        }

        return false;

    }

};



// Your WordDictionary object will be instantiated and called as such:

// WordDictionary wordDictionary;

// wordDictionary.addWord("word");

// wordDictionary.search("pattern");
