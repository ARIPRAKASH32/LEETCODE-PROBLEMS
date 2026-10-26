class Solution {
public:
    bool isValid(string s) {
        string st;
        for(int i = 0, n = s.length(); i < n; ++i){
            char ch = s[i];
            if(ch == 'c'){
                int m = st.length();
                if(m < 2 || st[m - 1] != 'b' || st[m - 2] != 'a') return false;
                st.pop_back(); st.pop_back();
            }
            else st.push_back(ch);
        }
        return st.empty();
    }
};
