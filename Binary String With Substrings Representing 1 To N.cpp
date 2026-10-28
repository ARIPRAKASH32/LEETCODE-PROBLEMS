class Solution {
public:
    bool queryString(string s, int n) {
        const int m = s.length();
        int i = 0;
        while(i < m && s[i] == '0') ++i;
        s = s.substr(i);
        while(n){
            string bin;
            for (int t = n--; t; t >>= 1) bin.push_back((t & 1) + '0');
            reverse(bin.begin(), bin.end());
            if(s.find(bin) == string::npos) return false;
        }
        return true;
    }
};
