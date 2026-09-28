// TrieNode class
class TrieNode{
public:
    TrieNode* child[26];
    bool endWord;
    
    TrieNode(){
        endWord = false;

        for (size_t i = 0; i < 26; i++)
            child[i] = nullptr;
    }
};

class MagicDictionary {
private:    
    TrieNode *root; // Trie root

    // Method to build the trie tree
    void buildWord(const string &s){
        TrieNode *curr = root;

        for(const char &c : s){
            if(!curr->child[c - 'a']) curr->child[c - 'a'] = new TrieNode();
            curr = curr->child[c - 'a'];
        }
        curr->endWord = true;
    }
    
    // Take in count that you have to make a mandatory
    // modification in the string, so you HAVE to skip one 
    // and only one character. You can use DFS to try all possible
    // ways.
    bool searchWithChange(const string &s, TrieNode *nd, const int idx, bool madeChange){
        if(!nd)
            return false;
        TrieNode *curr = nd;

        for (int i = idx; i < s.size(); i++){
            if(!madeChange){ // DFS
                for (int j = 0; j < 26; j++)
                    if(curr->child[j] && j != s[i] - 'a')
                        if(searchWithChange(s, curr->child[j], i + 1, true)) // Recursive call
                            return true;
            } 
            // If the string is not complete return false, continue otherwise
            if(curr->child[s[i] - 'a']) curr = curr->child[s[i] - 'a'];
            else return false;
        }
        
        // Return true if we are at the end of the word and we made a change
        return curr->endWord && madeChange;
    }

public:
    MagicDictionary() {
        root = new TrieNode();
    }
    
    void buildDict(vector<string> dictionary) {
        for(const string &s : dictionary)
            buildWord(s);
    }
    
    bool search(string searchWord) {
        return searchWithChange(searchWord, root, 0, false);
    }
};
