class CombinationIterator {
private:
    int i = 0;
    vector<string> ans;
    void solve(const string& characters, int combinationLength, int idx, string& temp){
        if(temp.size() == combinationLength){
            ans.push_back(temp);
            return;
        }
        if(temp.size() > combinationLength || idx == characters.size()){
            return;
        }
        else{
            solve(characters, combinationLength, idx + 1, temp);
            temp.push_back(characters[idx]);
            solve(characters, combinationLength, idx + 1, temp);
            temp.pop_back();
        }
    }
public:
    CombinationIterator(string characters, int combinationLength) {
        string temp = "";
        solve(characters, combinationLength, 0, temp);
        sort(ans.begin(), ans.end());
    }
    
    string next() {
        return ans[i++];
    }
    
    bool hasNext() {
        return i < ans.size();
    }
};
