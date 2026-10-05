class Solution {
public:
    // t.c: O(n)...
    // s.c: O(52)...
    string greatestLetter(string s) {
        int hash[52] = {0};
        char curr = 0;
        for(int i=0;i<s.length();i++){
            char ch = s[i]^32; 
            if(s[i] >= 'a' && s[i] <= 'z'){
                if(hash[ch-'A'] > 0){
                    if(!curr || curr<ch) {
                        curr = ch;
                    }
                }
                hash[s[i]-'a' + 26]++;
            }
            else if (s[i] >= 'A' && s[i] <= 'Z'){
                if(hash[ch-'a'+26] > 0){
                    if(!curr || curr<s[i]) {
                        curr = s[i];
                    }
                }
                hash[s[i]-'A']++;
            }
        }
        return (curr) ? string(1,curr) : "";
    }
};
