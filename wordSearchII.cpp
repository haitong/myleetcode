/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
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
    
    inline bool isChildrenExist(char c){
        return children_[(int)(c - 'a')] != NULL;
    }
    
    inline TrieNode * getChildren(int index){
        return children_[index];
    }
    
    inline TrieNode * getChildren(char c){
        return children_[(int)(c - 'a')];
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
    
    TrieNode * getRoot(){
        return root;
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

class Solution {
public:
    void findWord(vector<vector<char>>& board, vector<string> & res, string & curr, int i, int j, TrieNode * node){
        if(i < 0 || j < 0 || i > row-1 || j > col-1) return;
        curr.push_back(board[i][j]);
        if(node->isWord()){
            res.push_back(curr);
        }
        visited[i][j] = true;
        
        if(i - 1 >= 0 && !visited[i-1][j]){
            if(node->isChildrenExist(board[i-1][j])){
                findWord(board, res, curr, i-1, j, node->getChildren(board[i-1][j]));
            }
        }
        
        if( i + 1 < row && !visited[i+1][j]){
            if(node->isChildrenExist(board[i+1][j])){
                findWord(board, res, curr, i+1, j, node->getChildren(board[i+1][j]));
            }            
        }
        
        if( j + 1 < col && !visited[i][j+1]){
            if(node->isChildrenExist(board[i][j+1])){
                findWord(board, res, curr, i, j+1, node->getChildren(board[i][j+1]));
            }            
        }

        if( j - 1 >= 0 && !visited[i][j-1]){
            if(node->isChildrenExist(board[i][j-1])){
                findWord(board, res, curr, i, j-1, node->getChildren(board[i][j-1]));
            }            
        }
        
        visited[i][j] = false;
        curr.pop_back();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if(board.empty() || board[0].empty() || words.empty()) return res;
        row = board.size();
        col = board[0].size();
        
        tree = new Trie;
        for(string w : words){
            tree->insert(w);
        }
        
        for(int i =0; i < row; i++){
            vector<bool> tmp(col, false);
            visited.push_back(tmp);
        }
        
        string curr;
        for(int i =0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(tree->getRoot()->isChildrenExist(board[i][j])){
                    findWord(board, res, curr, i, j, tree->getRoot()->getChildren(board[i][j]));
                }
            }
        }
        
        set<string> ss;
        for(string s : res){
            ss.insert(s);
        }
        
        res.clear();
        
        for(string s : ss){
            res.push_back(s);
        }
        return res;
    }

private:
    Trie * tree;
    int row;
    int col;
    vector<vector<bool> > visited;
};

