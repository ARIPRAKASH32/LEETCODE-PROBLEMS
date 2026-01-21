//This is very very good on runtime
//due to very good pruning
//but it's avg in space (due to parent ptr)
class Solution {
private:
    struct node {
        node* childs[26];
        int size;
        string *word;
    };
    node* root = new node();
    void insert(string& word){
        auto temp = root;
        for(char c : word){
            if(!temp->childs[c-'a']){
                temp->childs[c-'a'] = new node();
                temp->size++;
            }
            temp = temp->childs[c-'a'];
        }
        temp->word = &word;
    }
public:
    vector<string> ans;
    int m;
    int n;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        for(string& word : words){
            insert(word);
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                search(board, i, j, root);
            }
        }
        return ans;
    }
    void search(vector<vector<char>>& board, int i, int j, node* dot){
        if(board[i][j] < 'a') return;
        auto parent = dot;
        dot = dot->childs[board[i][j]-'a'];
        if(!dot) return;

        if(dot->word){
            ans.push_back(*dot->word);
            if(!dot->size){
                parent->size--;
                delete dot;
                parent->childs[board[i][j]-'a'] = nullptr;
                return;
            }
            dot->word = nullptr;
        }
        
        board[i][j] -= 26;
        if(i+1 < m) search(board, i+1, j, dot);
        if(i > 0) search(board, i-1, j, dot);
        if(j+1 < n) search(board, i, j+1, dot);
        if(j > 0) search(board, i, j-1, dot);
        board[i][j] += 26;
        
        if(!dot->size){
            parent->size--;
            delete dot;
            parent->childs[board[i][j]-'a'] = nullptr;
        }
            
    }
};