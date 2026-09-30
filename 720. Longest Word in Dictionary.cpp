class Solution {
private :
    unordered_map<int,vector<string>> mp;
    bool canBeAns(string s1, string s2){
        if(s1.size() > s2.size()) return true;
        if(s1.size() == s2.size() && s1 < s2) return true;
        return false;
    }
    
    string dfs(vector<string>& words, string s1){
        string ans = "";
        vector<string> next = mp[s1.size()+1];
        for(auto s2 : next){
            string s3 = s2.substr(0,s1.size());
            if(s3 == s1) {
                if(canBeAns(s2,ans)) ans = s2;
                string temp = dfs(words, s2);
                if(canBeAns(temp,ans)) ans = temp;
            }
        }
        return ans;
    }

public:
    string longestWord(vector<string>& words) {
        for(auto x : words) mp[x.size()].push_back(x);
        if(mp[1].size() == 0) return "";
        string ans = "";
        vector<string>v  = mp[1];
        for(auto x : v){
            if(canBeAns(x,ans)) ans = x;
            string temp = dfs(words, x);
            if(canBeAns(temp,ans)) ans = temp;
        }
        return ans;
    }

};
